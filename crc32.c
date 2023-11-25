/* MIT License
 *
 * Copyright © 2010 - 2023 [Teddy Albon][tmalbon].
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * [tmalbon]: https://tmalbon.com
 */
/* Copyright (c) 2010 - 2013, Teodoro Albon Sr. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
// v1.1 : added FOR64BITS to force 64 bits compilation {Tue Jul 11 19:29:28 PHT 2017}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#define FOR64BITS
typedef unsigned char __byte;
typedef unsigned long __dword;
#ifndef O_BINARY
#define O_BINARY 0
#endif
#define OPEN_EXISTING 0
#define OPEN_ALWAYS 1
#undef _S
#define NULL_CSTR (const char * )0
#define NULL_STR (char * )0
#ifdef MSDOS
#define pascal __stdcall
#define unlink _unlink
#define snprintf _snprintf
#else
#define pascal
#endif
#define PROGNAME "crc32"
const char progname[] = PROGNAME;
#ifdef __for_unix
#define N_BUF_SIZE 1048576u
#else
#define N_BUF_SIZE 16384u
#endif
/* +++++++++++++++++++++++++++++++++++++++++++++++++++ *
 * [TAB SIZE is 4]
 *
 * Copyright (c) 1997-2011; UNPUBLISHED WORK of Teodoro M. Albon Sr.
 *
 * Automatically generated using (Ver: 2009.03.01.13) 'GenCrc32 -fgen_crc32 -ngenerate_crc32 -r -i'
 *
 * Removed other details here in favor of MIT LICENSE.
 *
 * see LICENSE.txt for INTELLIGENT TOYS, INC. LICENSE AGREEMENT
 * --------------------------------------------------*/
__dword
pascal
generate_crc32(__dword prev_crc, __byte * buf, int len);
//<<-- at line 73 of C:/_Winsock/Server/wsscrc32.cpp
//<<-- at line 64 of C:/BRISOFT/IF5COM32/SKDCRC32.CPP
/* The table values in CrcTable[] below are taken
   from the output of the sample software entitled:
   "Listing 18.1"
   "High Performance CRC-32 Computation Routine",
   From "The C Wizard's Programming Reference"
        "W. David Schwaderer"
        "Wiley Press, 1985"
        "Copyright 1988 W. David Schwaderer"
   Tested last July 31, 2001 by Teddy M. Albon Sr.;
   Included here for CRC32 version 1.01, PO2SM software.
*/
static __dword CrcTable[256] = {
/* 00 */ 0x00000000UL,  0x77073096UL,  0xEE0E612CUL,  0x990951BAUL,
/* 04 */ 0x076DC419UL,  0x706AF48FUL,  0xE963A535UL,  0x9E6495A3UL,
/* 08 */ 0x0EDB8832UL,  0x79DCB8A4UL,  0xE0D5E91EUL,  0x97D2D988UL,
/* 0C */ 0x09B64C2BUL,  0x7EB17CBDUL,  0xE7B82D07UL,  0x90BF1D91UL,
/* 10 */ 0x1DB71064UL,  0x6AB020F2UL,  0xF3B97148UL,  0x84BE41DEUL,
/* 14 */ 0x1ADAD47DUL,  0x6DDDE4EBUL,  0xF4D4B551UL,  0x83D385C7UL,
/* 18 */ 0x136C9856UL,  0x646BA8C0UL,  0xFD62F97AUL,  0x8A65C9ECUL,
/* 1C */ 0x14015C4FUL,  0x63066CD9UL,  0xFA0F3D63UL,  0x8D080DF5UL,
/* 20 */ 0x3B6E20C8UL,  0x4C69105EUL,  0xD56041E4UL,  0xA2677172UL,
/* 24 */ 0x3C03E4D1UL,  0x4B04D447UL,  0xD20D85FDUL,  0xA50AB56BUL,
/* 28 */ 0x35B5A8FAUL,  0x42B2986CUL,  0xDBBBC9D6UL,  0xACBCF940UL,
/* 2C */ 0x32D86CE3UL,  0x45DF5C75UL,  0xDCD60DCFUL,  0xABD13D59UL,
/* 30 */ 0x26D930ACUL,  0x51DE003AUL,  0xC8D75180UL,  0xBFD06116UL,
/* 34 */ 0x21B4F4B5UL,  0x56B3C423UL,  0xCFBA9599UL,  0xB8BDA50FUL,
/* 38 */ 0x2802B89EUL,  0x5F058808UL,  0xC60CD9B2UL,  0xB10BE924UL,
/* 3C */ 0x2F6F7C87UL,  0x58684C11UL,  0xC1611DABUL,  0xB6662D3DUL,
/* 40 */ 0x76DC4190UL,  0x01DB7106UL,  0x98D220BCUL,  0xEFD5102AUL,
/* 44 */ 0x71B18589UL,  0x06B6B51FUL,  0x9FBFE4A5UL,  0xE8B8D433UL,
/* 48 */ 0x7807C9A2UL,  0x0F00F934UL,  0x9609A88EUL,  0xE10E9818UL,
/* 4C */ 0x7F6A0DBBUL,  0x086D3D2DUL,  0x91646C97UL,  0xE6635C01UL,
/* 50 */ 0x6B6B51F4UL,  0x1C6C6162UL,  0x856530D8UL,  0xF262004EUL,
/* 54 */ 0x6C0695EDUL,  0x1B01A57BUL,  0x8208F4C1UL,  0xF50FC457UL,
/* 58 */ 0x65B0D9C6UL,  0x12B7E950UL,  0x8BBEB8EAUL,  0xFCB9887CUL,
/* 5C */ 0x62DD1DDFUL,  0x15DA2D49UL,  0x8CD37CF3UL,  0xFBD44C65UL,
/* 60 */ 0x4DB26158UL,  0x3AB551CEUL,  0xA3BC0074UL,  0xD4BB30E2UL,
/* 64 */ 0x4ADFA541UL,  0x3DD895D7UL,  0xA4D1C46DUL,  0xD3D6F4FBUL,
/* 68 */ 0x4369E96AUL,  0x346ED9FCUL,  0xAD678846UL,  0xDA60B8D0UL,
/* 6C */ 0x44042D73UL,  0x33031DE5UL,  0xAA0A4C5FUL,  0xDD0D7CC9UL,
/* 70 */ 0x5005713CUL,  0x270241AAUL,  0xBE0B1010UL,  0xC90C2086UL,
/* 74 */ 0x5768B525UL,  0x206F85B3UL,  0xB966D409UL,  0xCE61E49FUL,
/* 78 */ 0x5EDEF90EUL,  0x29D9C998UL,  0xB0D09822UL,  0xC7D7A8B4UL,
/* 7C */ 0x59B33D17UL,  0x2EB40D81UL,  0xB7BD5C3BUL,  0xC0BA6CADUL,
/* 80 */ 0xEDB88320UL,  0x9ABFB3B6UL,  0x03B6E20CUL,  0x74B1D29AUL,
/* 84 */ 0xEAD54739UL,  0x9DD277AFUL,  0x04DB2615UL,  0x73DC1683UL,
/* 88 */ 0xE3630B12UL,  0x94643B84UL,  0x0D6D6A3EUL,  0x7A6A5AA8UL,
/* 8C */ 0xE40ECF0BUL,  0x9309FF9DUL,  0x0A00AE27UL,  0x7D079EB1UL,
/* 90 */ 0xF00F9344UL,  0x8708A3D2UL,  0x1E01F268UL,  0x6906C2FEUL,
/* 94 */ 0xF762575DUL,  0x806567CBUL,  0x196C3671UL,  0x6E6B06E7UL,
/* 98 */ 0xFED41B76UL,  0x89D32BE0UL,  0x10DA7A5AUL,  0x67DD4ACCUL,
/* 9C */ 0xF9B9DF6FUL,  0x8EBEEFF9UL,  0x17B7BE43UL,  0x60B08ED5UL,
/* A0 */ 0xD6D6A3E8UL,  0xA1D1937EUL,  0x38D8C2C4UL,  0x4FDFF252UL,
/* A4 */ 0xD1BB67F1UL,  0xA6BC5767UL,  0x3FB506DDUL,  0x48B2364BUL,
/* A8 */ 0xD80D2BDAUL,  0xAF0A1B4CUL,  0x36034AF6UL,  0x41047A60UL,
/* AC */ 0xDF60EFC3UL,  0xA867DF55UL,  0x316E8EEFUL,  0x4669BE79UL,
/* B0 */ 0xCB61B38CUL,  0xBC66831AUL,  0x256FD2A0UL,  0x5268E236UL,
/* B4 */ 0xCC0C7795UL,  0xBB0B4703UL,  0x220216B9UL,  0x5505262FUL,
/* B8 */ 0xC5BA3BBEUL,  0xB2BD0B28UL,  0x2BB45A92UL,  0x5CB36A04UL,
/* BC */ 0xC2D7FFA7UL,  0xB5D0CF31UL,  0x2CD99E8BUL,  0x5BDEAE1DUL,
/* C0 */ 0x9B64C2B0UL,  0xEC63F226UL,  0x756AA39CUL,  0x026D930AUL,
/* C4 */ 0x9C0906A9UL,  0xEB0E363FUL,  0x72076785UL,  0x05005713UL,
/* C8 */ 0x95BF4A82UL,  0xE2B87A14UL,  0x7BB12BAEUL,  0x0CB61B38UL,
/* CC */ 0x92D28E9BUL,  0xE5D5BE0DUL,  0x7CDCEFB7UL,  0x0BDBDF21UL,
/* D0 */ 0x86D3D2D4UL,  0xF1D4E242UL,  0x68DDB3F8UL,  0x1FDA836EUL,
/* D4 */ 0x81BE16CDUL,  0xF6B9265BUL,  0x6FB077E1UL,  0x18B74777UL,
/* D8 */ 0x88085AE6UL,  0xFF0F6A70UL,  0x66063BCAUL,  0x11010B5CUL,
/* DC */ 0x8F659EFFUL,  0xF862AE69UL,  0x616BFFD3UL,  0x166CCF45UL,
/* E0 */ 0xA00AE278UL,  0xD70DD2EEUL,  0x4E048354UL,  0x3903B3C2UL,
/* E4 */ 0xA7672661UL,  0xD06016F7UL,  0x4969474DUL,  0x3E6E77DBUL,
/* E8 */ 0xAED16A4AUL,  0xD9D65ADCUL,  0x40DF0B66UL,  0x37D83BF0UL,
/* EC */ 0xA9BCAE53UL,  0xDEBB9EC5UL,  0x47B2CF7FUL,  0x30B5FFE9UL,
/* F0 */ 0xBDBDF21CUL,  0xCABAC28AUL,  0x53B39330UL,  0x24B4A3A6UL,
/* F4 */ 0xBAD03605UL,  0xCDD70693UL,  0x54DE5729UL,  0x23D967BFUL,
/* F8 */ 0xB3667A2EUL,  0xC4614AB8UL,  0x5D681B02UL,  0x2A6F2B94UL,
/* FC */ 0xB40BBE37UL,  0xC30C8EA1UL,  0x5A05DF1BUL,  0x2D02EF8DUL
};
//<<-- at line 146 of C:/BRISOFT/IF5COM32/SKDCRC32.CPP
//<<-- at line 159 of C:/_Winsock/Server/wsscrc32.cpp
//<<-- at line 207 of C:/_Winsock/Server/wsscrc32.cpp
/* HISTORY LIST
 *
 *  IF5CRC32.CPP; IF5COM32.dll; v1.10
 *        __dword pascal if5_GenCrc32(__dword, __byte *, long, char *, long);
 *
 *  WSSCRC32.cpp; WSSERVER.exe; v1.17 - v2.10
 *         __dword pascal wss_crc32(__dword,__byte *, long);
 *
 *  SKDCRC32.CPP; PSETUP.exe  ; v1.17
 *        __dword pascal des_crc32(__dword, __byte *, long);
 *
 *  SKDCRC32.CPP; SKDGEN32.exe; v1.20
 *        __dword pascal skd_crc32(__dword, __byte *, long);
 *
 *  CRC32.cpp; CRC32.exe; PO2SM Software v1997-2003
 *        see ../po2sm/PERMIT.TXT for license agreement
 */
__dword
pascal
generate_crc32(__dword prev_crc, __byte * buf, int len) {
    __dword j, cc, Crc = prev_crc;
    int lim;
    //<<-- at line 203 of C:/BRISOFT/IF5COM32/SKDCRC32.CPP
    //<<-- at line 234 of C:/_Winsock/Server/wsscrc32.cpp
    for (lim = 0; lim < len; lim++) {
        j = Crc;
        j ^= * buf++;
        cc = CrcTable[(int)(j & 255UL)];
        Crc = ((Crc >> 8) & 0x00FFFFFFUL) ^ cc;
    }
    //<<-- at line 210 of C:/BRISOFT/IF5COM32/SKDCRC32.CPP
    //<<-- at line 243 of C:/_Winsock/Server/wsscrc32.cpp
    return Crc;
} /*generate_crc32*/
/*
static char c_xlat[] = "0123456789ABCDEF\0\0";
static char *to_hex(char *p_buf, __byte c)
{
    char *buf = p_buf;
    *buf = c_xlat[(int)(15 & (c >> 4))];
    ++buf;
    *buf = c_xlat[(int)(15 & c)];
    ++buf;
    *buf = '\0';
    return buf;
} / *to_hex*/
// 77 = 10 + (16 * 3) + 1 + 16 + 2
#define MIN_BUFFER_SIZE 128
int main(int argc, char ** argv) {
    FILE * fo;
    int len;
    int hdl;
    __dword crc32;
    __dword n_read;
    __byte * p_byte;
    char * buf;
    const char * fname;
    const char * id;
    char buffer[N_BUF_SIZE];
    id = NULL_CSTR;
    if (argc != 2) {
        if (argc > 2) {
            if (0 == strcmp("-id", argv[2])) {
                id = "-id";
            }
        }
        if (!id) {
            fprintf(stderr, "%s v1.20 (c) tmalbonph@yahoo.com, albonteddy@gmail.com\n\n", progname);
            fprintf(stderr, "usage: %s infile [-id]\n", progname);
            fprintf(stderr, "where: content of source is crc32 calculate\n");
            fprintf(stderr, "       and result is written into console\n");
            fprintf(stderr, "       -id is to display only the CRC32\n");
            goto Exit;
        }
    }
    fname = (const char * ) argv[1];
    fo = stdout;
    memset(buffer, 0x0, sizeof(buffer));
    n_read = 0L;
    crc32 = (__dword) - 1L;
    hdl = open(fname, O_RDONLY | O_BINARY);
    if (hdl < 1) {
        //fprintf (stderr, "%s: ERROR opening '%s'\n", progname, fname);
        //        exit (1);
        goto Done;
    }
    do {
        n_read = (__dword) read(hdl, buffer, (size_t) N_BUF_SIZE);
        if (n_read == (__dword) - 1) break;
        len = (int) n_read;
        p_byte = (__byte * ) buffer;
        crc32 = generate_crc32(crc32, p_byte, len);
    } while (n_read == (__dword) N_BUF_SIZE);
    close(hdl);
    n_read = ~crc32;
    Done: ;
    #ifdef FOR64BITS
    // Fix warning /home/sid_root/projects/crc32/crc32.c:344:16:
    // warning: format ‘%x’ expects argument of type ‘unsigned int’,
    // but argument 3 has type ‘__dword {aka long unsigned int}’ [-Wformat=]
    if (id) {
        fprintf(fo, "%08x\n", (unsigned int) n_read);
    } else {
        fprintf(fo, "%08x    %s\n", (unsigned int) n_read, fname);
    }
    #else
    if (id) {
        fprintf(fo, "%08lx\n", n_read);
    } else {
        fprintf(fo, "%08lx    %s\n", n_read, fname);
    }
    #endif
    fflush(fo);
    Exit: ;
    exit(0);
    /*NOTREACH*/
    return 0;
} /*main*/
/*
 *EOF: crc32.c from show-hex.c from serial-from-crc32.c
 */