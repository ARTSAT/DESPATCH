/*
**      ARTSAT Despatch Application
**
**      Original Copyright (C) 2014 - 2014 HORIGUCHI Junshi.
**                                          http://iridium.jp/
**                                          zap00365@nifty.com
**      Portions Copyright (C) <year> <author>
**                                          <website>
**                                          <e-mail>
**      All rights reserved.
**
**      Version     Arduino
**      Website     http://artsat.jp/
**      E-mail      info@artsat.jp
**
**      This source code is for Arduino IDE.
**      Arduino 1.0.5
**
**      WordTable.h
**
**      ------------------------------------------------------------------------
**
**      GNU GENERAL PUBLIC LICENSE (GPLv3)
**
**      This program is free software: you can redistribute it and/or modify
**      it under the terms of the GNU General Public License as published by
**      the Free Software Foundation, either version 3 of the License,
**      or (at your option) any later version.
**      This program is distributed in the hope that it will be useful,
**      but WITHOUT ANY WARRANTY; without even the implied warranty of
**      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**      See the GNU General Public License for more details.
**      You should have received a copy of the GNU General Public License
**      along with this program. If not, see <http://www.gnu.org/licenses/>.
**
**      このプログラムはフリーソフトウェアです。あなたはこれをフリーソフトウェア財団によって発行された
**      GNU 一般公衆利用許諾書（バージョン 3 か、それ以降のバージョンのうちどれか）が定める条件の下で
**      再頒布または改変することができます。このプログラムは有用であることを願って頒布されますが、
**      *全くの無保証* です。商業可能性の保証や特定目的への適合性は、言外に示されたものも含め全く存在しません。
**      詳しくは GNU 一般公衆利用許諾書をご覧ください。
**      あなたはこのプログラムと共に GNU 一般公衆利用許諾書のコピーを一部受け取っているはずです。
**      もし受け取っていなければ <http://www.gnu.org/licenses/> をご覧ください。
*/

#ifndef __WORDTABLE_H
#define __WORDTABLE_H

static char const g_color_000[] PROGMEM = "whit";
static char const g_color_001[] PROGMEM = "whit";
static char const g_color_002[] PROGMEM = "whit";
static char const g_color_003[] PROGMEM = "whit";
static char const g_color_004[] PROGMEM = "whit";
static char const g_color_005[] PROGMEM = "whit";
static char const g_color_006[] PROGMEM = "whit";
static char const g_color_007[] PROGMEM = "whit";
static char const g_color_008[] PROGMEM = "hlot";
static char const g_color_009[] PROGMEM = "mulb";
static char const g_color_010[] PROGMEM = "prpl";
static char const g_color_011[] PROGMEM = "volt";
static char const g_color_012[] PROGMEM = "blvl";
static char const g_color_013[] PROGMEM = "indg";
static char const g_color_014[] PROGMEM = "pers";
static char const g_color_015[] PROGMEM = "blue";
static char const g_color_016[] PROGMEM = "sprb";
static char const g_color_017[] PROGMEM = "sphr";
static char const g_color_018[] PROGMEM = "cblt";
static char const g_color_019[] PROGMEM = "azur";
static char const g_color_020[] PROGMEM = "crnf";
static char const g_color_021[] PROGMEM = "cerl";
static char const g_color_022[] PROGMEM = "arct";
static char const g_color_023[] PROGMEM = "cyan";
static char const g_color_024[] PROGMEM = "opal";
static char const g_color_025[] PROGMEM = "trqs";
static char const g_color_026[] PROGMEM = "aqmr";
static char const g_color_027[] PROGMEM = "sprg";
static char const g_color_028[] PROGMEM = "seag";
static char const g_color_029[] PROGMEM = "mlct";
static char const g_color_030[] PROGMEM = "emrd";
static char const g_color_031[] PROGMEM = "gren";
static char const g_color_032[] PROGMEM = "sapg";
static char const g_color_033[] PROGMEM = "hrlq";
static char const g_color_034[] PROGMEM = "pstc";
static char const g_color_035[] PROGMEM = "chtr";
static char const g_color_036[] PROGMEM = "sprg";
static char const g_color_037[] PROGMEM = "lime";
static char const g_color_038[] PROGMEM = "appl";
static char const g_color_039[] PROGMEM = "yelw";
static char const g_color_040[] PROGMEM = "gold";
static char const g_color_041[] PROGMEM = "ambr";
static char const g_color_042[] PROGMEM = "gmbg";
static char const g_color_043[] PROGMEM = "orag";
static char const g_color_044[] PROGMEM = "tngl";
static char const g_color_045[] PROGMEM = "vrmn";
static char const g_color_046[] PROGMEM = "sclt";
static char const g_color_047[] PROGMEM = "red_";
static char const g_color_048[] PROGMEM = "amrt";
static char const g_color_049[] PROGMEM = "crms";
static char const g_color_050[] PROGMEM = "rsbr";
static char const g_color_051[] PROGMEM = "rose";
static char const g_color_052[] PROGMEM = "cers";
static char const g_color_053[] PROGMEM = "fcha";
static char const g_color_054[] PROGMEM = "orcd";
static char const g_color_055[] PROGMEM = "mgnt";
static char const g_color_056[] PROGMEM = "blck";
static char const g_color_057[] PROGMEM = "blck";
static char const g_color_058[] PROGMEM = "blck";
static char const g_color_059[] PROGMEM = "blck";
static char const g_color_060[] PROGMEM = "blck";
static char const g_color_061[] PROGMEM = "blck";
static char const g_color_062[] PROGMEM = "blck";
static char const g_color_063[] PROGMEM = "blck";
static PGM_P g_color[] PROGMEM = {
    g_color_000,
    g_color_001,
    g_color_002,
    g_color_003,
    g_color_004,
    g_color_005,
    g_color_006,
    g_color_007,
    g_color_008,
    g_color_009,
    g_color_010,
    g_color_011,
    g_color_012,
    g_color_013,
    g_color_014,
    g_color_015,
    g_color_016,
    g_color_017,
    g_color_018,
    g_color_019,
    g_color_020,
    g_color_021,
    g_color_022,
    g_color_023,
    g_color_024,
    g_color_025,
    g_color_026,
    g_color_027,
    g_color_028,
    g_color_029,
    g_color_030,
    g_color_031,
    g_color_032,
    g_color_033,
    g_color_034,
    g_color_035,
    g_color_036,
    g_color_037,
    g_color_038,
    g_color_039,
    g_color_040,
    g_color_041,
    g_color_042,
    g_color_043,
    g_color_044,
    g_color_045,
    g_color_046,
    g_color_047,
    g_color_048,
    g_color_049,
    g_color_050,
    g_color_051,
    g_color_052,
    g_color_053,
    g_color_054,
    g_color_055,
    g_color_056,
    g_color_057,
    g_color_058,
    g_color_059,
    g_color_060,
    g_color_061,
    g_color_062,
    g_color_063
};
static char const g_rhythm_000[] PROGMEM = "abim";
static char const g_rhythm_001[] PROGMEM = "adji";
static char const g_rhythm_002[] PROGMEM = "affa";
static char const g_rhythm_003[] PROGMEM = "alla";
static char const g_rhythm_004[] PROGMEM = "amai";
static char const g_rhythm_005[] PROGMEM = "amen";
static char const g_rhythm_006[] PROGMEM = "amma";
static char const g_rhythm_007[] PROGMEM = "assa";
static char const g_rhythm_008[] PROGMEM = "aula";
static char const g_rhythm_009[] PROGMEM = "auli";
static char const g_rhythm_010[] PROGMEM = "bala";
static char const g_rhythm_011[] PROGMEM = "balo";
static char const g_rhythm_012[] PROGMEM = "band";
static char const g_rhythm_013[] PROGMEM = "bang";
static char const g_rhythm_014[] PROGMEM = "bann";
static char const g_rhythm_015[] PROGMEM = "beri";
static char const g_rhythm_016[] PROGMEM = "bimb";
static char const g_rhythm_017[] PROGMEM = "bimm";
static char const g_rhythm_018[] PROGMEM = "binb";
static char const g_rhythm_019[] PROGMEM = "binn";
static char const g_rhythm_020[] PROGMEM = "blas";
static char const g_rhythm_021[] PROGMEM = "blau";
static char const g_rhythm_022[] PROGMEM = "blon";
static char const g_rhythm_023[] PROGMEM = "bluk";
static char const g_rhythm_024[] PROGMEM = "blun";
static char const g_rhythm_025[] PROGMEM = "brus";
static char const g_rhythm_026[] PROGMEM = "bulo";
static char const g_rhythm_027[] PROGMEM = "bumb";
static char const g_rhythm_028[] PROGMEM = "cado";
static char const g_rhythm_029[] PROGMEM = "dibl";
static char const g_rhythm_030[] PROGMEM = "dibu";
static char const g_rhythm_031[] PROGMEM = "didi";
static char const g_rhythm_032[] PROGMEM = "diga";
static char const g_rhythm_033[] PROGMEM = "dori";
static char const g_rhythm_034[] PROGMEM = "drid";
static char const g_rhythm_035[] PROGMEM = "elif";
static char const g_rhythm_036[] PROGMEM = "falo";
static char const g_rhythm_037[] PROGMEM = "fant";
static char const g_rhythm_038[] PROGMEM = "gadj";
static char const g_rhythm_039[] PROGMEM = "gado";
static char const g_rhythm_040[] PROGMEM = "gaga";
static char const g_rhythm_041[] PROGMEM = "gala";
static char const g_rhythm_042[] PROGMEM = "glan";
static char const g_rhythm_043[] PROGMEM = "glas";
static char const g_rhythm_044[] PROGMEM = "glig";
static char const g_rhythm_045[] PROGMEM = "gooo";
static char const g_rhythm_046[] PROGMEM = "gram";
static char const g_rhythm_047[] PROGMEM = "hoge";
static char const g_rhythm_048[] PROGMEM = "hooo";
static char const g_rhythm_049[] PROGMEM = "hops";
static char const g_rhythm_050[] PROGMEM = "ibar";
static char const g_rhythm_051[] PROGMEM = "igla";
static char const g_rhythm_052[] PROGMEM = "imai";
static char const g_rhythm_053[] PROGMEM = "imba";
static char const g_rhythm_054[] PROGMEM = "imzi";
static char const g_rhythm_055[] PROGMEM = "inai";
static char const g_rhythm_056[] PROGMEM = "iola";
static char const g_rhythm_057[] PROGMEM = "ital";
static char const g_rhythm_058[] PROGMEM = "izim";
static char const g_rhythm_059[] PROGMEM = "jama";
static char const g_rhythm_060[] PROGMEM = "jame";
static char const g_rhythm_061[] PROGMEM = "kata";
static char const g_rhythm_062[] PROGMEM = "lala";
static char const g_rhythm_063[] PROGMEM = "laul";
static char const g_rhythm_064[] PROGMEM = "laxa";
static char const g_rhythm_065[] PROGMEM = "leng";
static char const g_rhythm_066[] PROGMEM = "lima";
static char const g_rhythm_067[] PROGMEM = "ling";
static char const g_rhythm_068[] PROGMEM = "lita";
static char const g_rhythm_069[] PROGMEM = "llal";
static char const g_rhythm_070[] PROGMEM = "lomi";
static char const g_rhythm_071[] PROGMEM = "long";
static char const g_rhythm_072[] PROGMEM = "lonn";
static char const g_rhythm_073[] PROGMEM = "looo";
static char const g_rhythm_074[] PROGMEM = "lopi";
static char const g_rhythm_075[] PROGMEM = "luji";
static char const g_rhythm_076[] PROGMEM = "luku";
static char const g_rhythm_077[] PROGMEM = "lung";
static char const g_rhythm_078[] PROGMEM = "malo";
static char const g_rhythm_079[] PROGMEM = "mbal";
static char const g_rhythm_080[] PROGMEM = "mbra";
static char const g_rhythm_081[] PROGMEM = "mini";
static char const g_rhythm_082[] PROGMEM = "mzim";
static char const g_rhythm_083[] PROGMEM = "nban";
static char const g_rhythm_084[] PROGMEM = "ndri";
static char const g_rhythm_085[] PROGMEM = "negr";
static char const g_rhythm_086[] PROGMEM = "noze";
static char const g_rhythm_087[] PROGMEM = "ogro";
static char const g_rhythm_088[] PROGMEM = "olim";
static char const g_rhythm_089[] PROGMEM = "omen";
static char const g_rhythm_090[] PROGMEM = "omin";
static char const g_rhythm_091[] PROGMEM = "onni";
static char const g_rhythm_092[] PROGMEM = "oooo";
static char const g_rhythm_093[] PROGMEM = "orsu";
static char const g_rhythm_094[] PROGMEM = "osso";
static char const g_rhythm_095[] PROGMEM = "ozer";
static char const g_rhythm_096[] PROGMEM = "palo";
static char const g_rhythm_097[] PROGMEM = "palu";
static char const g_rhythm_098[] PROGMEM = "pimp";
static char const g_rhythm_099[] PROGMEM = "pinx";
static char const g_rhythm_100[] PROGMEM = "piyo";
static char const g_rhythm_101[] PROGMEM = "purz";
static char const g_rhythm_102[] PROGMEM = "rabi";
static char const g_rhythm_103[] PROGMEM = "rhin";
static char const g_rhythm_104[] PROGMEM = "rida";
static char const g_rhythm_105[] PROGMEM = "ridi";
static char const g_rhythm_106[] PROGMEM = "ross";
static char const g_rhythm_107[] PROGMEM = "sala";
static char const g_rhythm_108[] PROGMEM = "sass";
static char const g_rhythm_109[] PROGMEM = "sola";
static char const g_rhythm_110[] PROGMEM = "ssas";
static char const g_rhythm_111[] PROGMEM = "tata";
static char const g_rhythm_112[] PROGMEM = "teru";
static char const g_rhythm_113[] PROGMEM = "torr";
static char const g_rhythm_114[] PROGMEM = "trom";
static char const g_rhythm_115[] PROGMEM = "tuff";
static char const g_rhythm_116[] PROGMEM = "uffm";
static char const g_rhythm_117[] PROGMEM = "urul";
static char const g_rhythm_118[] PROGMEM = "velo";
static char const g_rhythm_119[] PROGMEM = "viol";
static char const g_rhythm_120[] PROGMEM = "wowo";
static char const g_rhythm_121[] PROGMEM = "xato";
static char const g_rhythm_122[] PROGMEM = "zall";
static char const g_rhythm_123[] PROGMEM = "zamm";
static char const g_rhythm_124[] PROGMEM = "zanz";
static char const g_rhythm_125[] PROGMEM = "zimb";
static char const g_rhythm_126[] PROGMEM = "zimz";
static char const g_rhythm_127[] PROGMEM = "zing";
static PGM_P g_rhythm[] PROGMEM = {
    g_rhythm_000,
    g_rhythm_001,
    g_rhythm_002,
    g_rhythm_003,
    g_rhythm_004,
    g_rhythm_005,
    g_rhythm_006,
    g_rhythm_007,
    g_rhythm_008,
    g_rhythm_009,
    g_rhythm_010,
    g_rhythm_011,
    g_rhythm_012,
    g_rhythm_013,
    g_rhythm_014,
    g_rhythm_015,
    g_rhythm_016,
    g_rhythm_017,
    g_rhythm_018,
    g_rhythm_019,
    g_rhythm_020,
    g_rhythm_021,
    g_rhythm_022,
    g_rhythm_023,
    g_rhythm_024,
    g_rhythm_025,
    g_rhythm_026,
    g_rhythm_027,
    g_rhythm_028,
    g_rhythm_029,
    g_rhythm_030,
    g_rhythm_031,
    g_rhythm_032,
    g_rhythm_033,
    g_rhythm_034,
    g_rhythm_035,
    g_rhythm_036,
    g_rhythm_037,
    g_rhythm_038,
    g_rhythm_039,
    g_rhythm_040,
    g_rhythm_041,
    g_rhythm_042,
    g_rhythm_043,
    g_rhythm_044,
    g_rhythm_045,
    g_rhythm_046,
    g_rhythm_047,
    g_rhythm_048,
    g_rhythm_049,
    g_rhythm_050,
    g_rhythm_051,
    g_rhythm_052,
    g_rhythm_053,
    g_rhythm_054,
    g_rhythm_055,
    g_rhythm_056,
    g_rhythm_057,
    g_rhythm_058,
    g_rhythm_059,
    g_rhythm_060,
    g_rhythm_061,
    g_rhythm_062,
    g_rhythm_063,
    g_rhythm_064,
    g_rhythm_065,
    g_rhythm_066,
    g_rhythm_067,
    g_rhythm_068,
    g_rhythm_069,
    g_rhythm_070,
    g_rhythm_071,
    g_rhythm_072,
    g_rhythm_073,
    g_rhythm_074,
    g_rhythm_075,
    g_rhythm_076,
    g_rhythm_077,
    g_rhythm_078,
    g_rhythm_079,
    g_rhythm_080,
    g_rhythm_081,
    g_rhythm_082,
    g_rhythm_083,
    g_rhythm_084,
    g_rhythm_085,
    g_rhythm_086,
    g_rhythm_087,
    g_rhythm_088,
    g_rhythm_089,
    g_rhythm_090,
    g_rhythm_091,
    g_rhythm_092,
    g_rhythm_093,
    g_rhythm_094,
    g_rhythm_095,
    g_rhythm_096,
    g_rhythm_097,
    g_rhythm_098,
    g_rhythm_099,
    g_rhythm_100,
    g_rhythm_101,
    g_rhythm_102,
    g_rhythm_103,
    g_rhythm_104,
    g_rhythm_105,
    g_rhythm_106,
    g_rhythm_107,
    g_rhythm_108,
    g_rhythm_109,
    g_rhythm_110,
    g_rhythm_111,
    g_rhythm_112,
    g_rhythm_113,
    g_rhythm_114,
    g_rhythm_115,
    g_rhythm_116,
    g_rhythm_117,
    g_rhythm_118,
    g_rhythm_119,
    g_rhythm_120,
    g_rhythm_121,
    g_rhythm_122,
    g_rhythm_123,
    g_rhythm_124,
    g_rhythm_125,
    g_rhythm_126,
    g_rhythm_127
};

#endif
