/*
**      ARTSAT Project
**
**      Original Copyright (C) 2014 - 2014 HORIGUCHI Junshi.
**                                          http://iridium.jp/
**                                          zap00365@nifty.com
**      Portions Copyright (C) <year> <author>
**                                          <website>
**                                          <e-mail>
**      Version     POSIX / C++11
**      Website     http://artsat.jp/
**      E-mail      info@artsat.jp
**
**      This source code is for Xcode.
**      Xcode 6.1 (Apple LLVM 6.0)
**
**      main.cpp
**
**      ------------------------------------------------------------------------
**
**      The MIT License (MIT)
**
**      Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
**      associated documentation files (the "Software"), to deal in the Software without restriction,
**      including without limitation the rights to use, copy, modify, merge, publish, distribute,
**      sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
**      furnished to do so, subject to the following conditions:
**      The above copyright notice and this permission notice shall be included in all copies or
**      substantial portions of the Software.
**      THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
**      BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
**      IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
**      WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
**      OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
**      以下に定める条件に従い、本ソフトウェアおよび関連文書のファイル（以下「ソフトウェア」）の複製を
**      取得するすべての人に対し、ソフトウェアを無制限に扱うことを無償で許可します。
**      これには、ソフトウェアの複製を使用、複写、変更、結合、掲載、頒布、サブライセンス、および、または販売する権利、
**      およびソフトウェアを提供する相手に同じことを許可する権利も無制限に含まれます。
**      上記の著作権表示および本許諾表示を、ソフトウェアのすべての複製または重要な部分に記載するものとします。
**      ソフトウェアは「現状のまま」で、明示であるか暗黙であるかを問わず、何らの保証もなく提供されます。
**      ここでいう保証とは、商品性、特定の目的への適合性、および権利非侵害についての保証も含みますが、それに限定されるものではありません。
**      作者または著作権者は、契約行為、不法行為、またはそれ以外であろうと、ソフトウェアに起因または関連し、
**      あるいはソフトウェアの使用またはその他の扱いによって生じる一切の請求、損害、その他の義務について何らの責任も負わないものとします。
*/

#include <iostream>

#define __USE_COLOR

using namespace::std;

static char const* baudot_table_ltrs[] = {
    "N",
    "e",
    "[LF]",
    "a",
    " ",
    "s",
    "i",
    "u",
    "[CR]",
    "d",
    "r",
    "j",
    "n",
    "f",
    "c",
    "k",
    "t",
    "z",
    "l",
    "w",
    "h",
    "y",
    "p",
    "q",
    "o",
    "b",
    "g",
    "F",
    "m",
    "x",
    "v",
    "L"
};
static char const* baudot_table_figs[] = {
    "N",
    "3",
    "[LF]",
    "-",
    " ",
    "'",
    "8",
    "7",
    "[CR]",
    "$",
    "4",
    "'",
    ",",
    "!",
    ":",
    "(",
    "5",
    "+",
    ")",
    "2",
    "*",
    "6",
    "0",
    "1",
    "9",
    "?",
    "&",
    "F",
    ".",
    "/",
    ";",
    "L"
};

bool is_01(string const& param)
{
    int i;
    bool result(true);
    
    for (i = 0; i < param.size(); ++i) {
        if (!(param[i] == '0' || param[i] == '1')) {
            result = false;
        }
    }
    return result;
}

bool demanchester(string const& param, bool clock, string* decode, int* size)
{
    int i;
    bool result(true);
    
    decode->clear();
    *size = 0;
    if (!clock) {
        for (i = 0; i < param.size() / 2; ++i) {
            if (param[i * 2 + 0] == '1' && param[i * 2 + 1] == '0') {
                *decode += '1';
                *size += 2;
            }
            else if (param[i * 2 + 0] == '0' && param[i * 2 + 1] == '1') {
                *decode += '0';
                *size += 2;
            }
            else {
                result = false;
                break;
            }
        }
    }
    else {
        if (param[0] == '1') {
            *decode = '0';
            ++*size;
        }
        else if (param[0] == '0') {
            *decode = '1';
            ++*size;
        }
        else {
            result = false;
        }
        if (result) {
            for (i = 0; i < (param.size() - 1) / 2; ++i) {
                if (param[i * 2 + 1] == '1' && param[i * 2 + 2] == '0') {
                    *decode += '1';
                    *size += 2;
                }
                else if (param[i * 2 + 1] == '0' && param[i * 2 + 2] == '1') {
                    *decode += '0';
                    *size += 2;
                }
                else {
                    result = false;
                    break;
                }
            }
        }
    }
    return result;
}

bool debaudot(string const& param, string* decode, int* size)
{
    unsigned char data;
    bool ltrs;
    int raw;
    int bits15;
    string value;
    char temp[16];
    int i;
    int j;
    bool result(true);
    
    decode->clear();
    *size = 0;
    ltrs = true;
    raw = 0;
    bits15 = 0;
    for (i = 0; i < param.size() / 5; ++i) {
        data = 0;
        for (j = 4; j >= 0; --j) {
            data <<= 1;
            if (param[i * 5 + j] == '0') {
                ++*size;
            }
            else if (param[i * 5 + j] == '1') {
                data |= 1;
                ++*size;
            }
            else {
                result = false;
                break;
            }
        }
        if (result) {
            if (raw > 0) {
                bits15 <<= 5;
                bits15 |= data;
                if (--raw <= 0) {
                    snprintf(temp, sizeof(temp), "[%d]", bits15);
                    *decode += temp;
                }
            }
            else {
                value = (ltrs) ? (baudot_table_ltrs[data]) : (baudot_table_figs[data]);
                if (value == "L") {
                    ltrs = true;
                }
                else if (value == "F") {
                    ltrs = false;
                }
                else if (value == "N") {
                    raw = 3;
                    bits15 = 0;
                }
                *decode += value;
            }
        }
        else {
            break;
        }
    }
    return result;
}

int main(int argc, const char * argv[])
{
    string input;
    string buffer;
    string baudot;
    string phrase;
    int size;
    bool clock;
    bool clear;
    bool quit;
    
    clock = false;
    clear = false;
    quit = false;
    while (!quit) {
        cout << "# ";
        cin >> input;
        if (is_01(input)) {
            if (clear) {
                buffer.clear();
                clear = false;
            }
            buffer += input;
            cout << "sequence = " << buffer << endl;
        }
        else if (input == "clock0") {
            clock = false;
            cout << "changed clock = 0" << endl;
        }
        else if (input == "clock1") {
            clock = true;
            cout << "changed clock = 1" << endl;
        }
        else if (input == "decode") {
            clear = true;
            cout << "clock = " << ((clock) ? ("1") : ("0")) << endl;
            cout << "sequence = " << buffer << endl;
            if (demanchester(buffer, clock, &baudot, &size)) {
                if (debaudot(baudot, &phrase, &size)) {
#ifdef __USE_COLOR
                    cout << "\x1b[32m";
#endif
                    cout.width(11 + size * 2);
                    cout << "^" << endl;
                    cout.width(0);
                    cout << "decode = " << phrase << endl;
#ifdef __USE_COLOR
                    cout << "\x1b[39m";
#endif
                }
                else {
#ifdef __USE_COLOR
                    cout << "\x1b[31m";
#endif
                    cout << "error: can't decode baudot" << endl;
#ifdef __USE_COLOR
                    cout << "\x1b[39m";
#endif
                }
            }
            else {
#ifdef __USE_COLOR
                cout << "\x1b[32m";
#endif
                cout.width(12 + size);
                cout << "^";
                cout.width(0);
#ifdef __USE_COLOR
                cout << "\x1b[31m";
#endif
                cout << "^" << endl;
                cout << "error: invalid clock phase" << endl;
#ifdef __USE_COLOR
                cout << "\x1b[39m";
#endif
            }
        }
        else if (input == "exit") {
            quit = true;
        }
        else if (input == "help") {
            cout << "usage: debaudot [< input]" << endl;
            cout << "" << endl;
            cout << "decode manchester sequence and baudot code of DESPATCH's poem" << endl;
            cout << "" << endl;
            cout << "debaudot has no command line parameter." << endl;
            cout << "user can use operation commands in debaudot's interpreter console." << endl;
            cout << "also user can pass all operation commands via stdin pipeline." << endl;
            cout << "" << endl;
            cout << "step 1. input 1010100110011010... manchester sequence. user can break the line." << endl;
            cout << "        input data will be automatically connected until 'decode' command." << endl;
            cout << "step 2. use 'decode' command." << endl;
            cout << "step 3. continue step 1 and step 2 while user needs to process everything." << endl;
            cout << "" << endl;
            cout << "command:" << endl;
            cout << "  clock0: change clock phase to 0 (default)" << endl;
            cout << "          1^01^01^00^11^0    ^ is upper edge of clock" << endl;
            cout << "  clock1: change clock phase to 1" << endl;
            cout << "          ^10^10^10^01^10    ^ is upper edge of clock" << endl;
            cout << "  decode: decode manchester sequence and baudot code" << endl;
            cout << "    exit: exit from debaudot's interpreter" << endl;
            cout << "    help: show this help" << endl;
        }
        else {
            cout << "?" << endl;
        }
    }
    return 0;
}
