#ifdef USE_IMG_CUNDO1_COLORS
const ULONG IMG_CUndo1_colors[96] =
{
  0x00000000,0xffffffff,0x00000000,
  0xf7f7f7f7,0xf7f7f7f7,0xf7f7f7f7,
  0xebebebeb,0xe7e7e7e7,0xe7e7e7e7,
  0xe3e3e3e3,0xe3e3e3e3,0xe3e3e3e3,
  0x75757575,0x71717171,0x71717171,
  0xd6d6d6d6,0xd6d6d6d6,0xd6d6d6d6,
  0xcacacaca,0xcececece,0xd6d6d6d6,
  0xbebebebe,0xbebebebe,0xbebebebe,
  0xb6b6b6b6,0xb6b6b6b6,0xb2b2b2b2,
  0xaaaaaaaa,0xaaaaaaaa,0xaeaeaeae,
  0xa2a2a2a2,0xa2a2a2a2,0xa2a2a2a2,
  0x96969696,0x96969696,0x96969696,
  0x86868686,0x8a8a8a8a,0x8a8a8a8a,
  0x79797979,0x7d7d7d7d,0x7d7d7d7d,
  0x69696969,0x69696969,0x69696969,
  0x55555555,0x55555555,0x69696969,
  0xffffffff,0xffffffff,0xffffffff,
  0xcacacaca,0x65656565,0x45454545,
  0xc6c6c6c6,0x39393939,0x49494949,
  0xe7e7e7e7,0x5d5d5d5d,0x69696969,
  0x9a9a9a9a,0x00000000,0xffffffff,
  0x65656565,0x00000000,0xcacacaca,
  0xbabababa,0x75757575,0x00000000,
  0x9a9a9a9a,0x55555555,0x00000000,
  0xffffffff,0xaaaaaaaa,0x55555555,
  0xdfdfdfdf,0x8a8a8a8a,0x45454545,
  0xffffffff,0xffffffff,0x00000000,
  0x65656565,0x8a8a8a8a,0x65656565,
  0x45454545,0xaaaaaaaa,0x75757575,
  0x10101010,0x75757575,0x55555555,
  0x35353535,0x35353535,0x35353535,
  0xefefefef,0xefefefef,0xefefefef,
};
#endif

//Width 35 Height 35 Depth 5 - converting...
#define IMG_CUNDO1_WIDTH        35
#define IMG_CUNDO1_HEIGHT       35
#define IMG_CUNDO1_DEPTH         5
#define IMG_CUNDO1_COMPRESSION   0
#define IMG_CUNDO1_MASKING       2

#ifdef USE_IMG_CUNDO1_HEADER
const struct BitMapHeader IMG_CUndo1_header =
{ 35,35,146,255,5,2,0,0,0,22,22,1024,768 };
#endif

//ifdef USE_IMG_CUNDO1_BODY
const UBYTE IMG_CUndo1_body[1050] = {
0x00,0x02,0x14,0x00,0x00,0x00,0x00,0x00,0x84,0x00,0x00,0x00,0x00,0x07,0xf8,
0x00,0x00,0x00,0x00,0x06,0x9c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x28,0x0c,0x00,0x00,0x00,0x00,0x1f,0x00,0x80,0x00,0x00,0x00,0x3f,0xff,
0x00,0x00,0x00,0x00,0x3f,0x0f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xe0,0x18,0x40,0x00,0x00,0x00,0x7f,0x00,0x60,0x00,0x00,0x00,0xff,0xff,
0x80,0x00,0x00,0x00,0xff,0x1f,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xc2,0x77,0x60,0x00,0x00,0x01,0xff,0xfd,0x70,0x00,0x00,0x01,0xf4,0x0c,
0x80,0x00,0x00,0x01,0xf8,0x03,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x03,0x86,0xfd,0x00,0x00,0x00,0x03,0xd1,0xf3,0x78,0x00,0x00,0x03,0xc0,0x0f,
0x00,0x00,0x00,0x03,0xe0,0x00,0xf8,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x07,0x65,0xfb,0xe4,0x00,0x00,0x07,0x0f,0xff,0xd8,0x00,0x00,0x07,0xc3,0xff,
0xc0,0x00,0x00,0x07,0x80,0x00,0x3c,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x0e,0x7f,0xff,0x9c,0x00,0x00,0x0f,0x8f,0xff,0x80,0x00,0x00,0x0e,0x1f,0xff,
0x80,0x00,0x00,0x0f,0x00,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x0d,0xdf,0xff,0xf9,0x00,0x00,0x1e,0x7f,0xff,0xc1,0x00,0x00,0x1c,0x3f,0xff,
0xc1,0x00,0x00,0x1e,0x00,0x00,0x3e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x3d,0xff,0xff,0xc7,0x80,0x00,0x1e,0xff,0x1f,0xdb,0x80,0x00,0x38,0x7f,0xff,
0xc3,0x80,0x00,0x3c,0x00,0xe0,0x3c,0x00,0x00,0x00,0x00,0xe0,0x00,0x00,0x00,
0x35,0xff,0xff,0xf3,0x80,0x00,0x3d,0xfe,0x0f,0xef,0x80,0x00,0x38,0xff,0xff,
0xe3,0x80,0x00,0x38,0x01,0xf0,0x1c,0x00,0x00,0x02,0x01,0xf0,0x00,0x00,0x00,
0x63,0xff,0xff,0xf7,0xc0,0x00,0x31,0xf4,0x07,0xfd,0xc0,0x00,0x71,0xff,0xff,
0xf1,0xc0,0x00,0x78,0x0b,0xf8,0x0e,0x00,0x00,0x04,0x0b,0xf8,0x00,0x00,0x00,
0x23,0xff,0xff,0xfb,0x00,0x00,0x79,0xf0,0x03,0xf3,0xc0,0x00,0x73,0xff,0xff,
0xf5,0xc0,0x00,0x70,0x0f,0xfc,0x0e,0x00,0x00,0x04,0x0f,0xfc,0x00,0x00,0x00,
0x43,0xff,0xff,0xfc,0x00,0x00,0x77,0xf0,0x41,0xfc,0xc0,0x00,0x63,0xff,0xff,
0xfa,0xc0,0x00,0x70,0x0f,0xbe,0x07,0x00,0x00,0x08,0x0f,0xbe,0x00,0x00,0x00,
0x17,0xff,0xff,0xf8,0x40,0x00,0x77,0xf0,0xe7,0xfd,0xa0,0x00,0xf3,0xff,0xff,
0xfa,0xe0,0x00,0xe0,0x0f,0x18,0x07,0x00,0x00,0x08,0x0f,0x18,0x00,0x00,0x00,
0x17,0xff,0xff,0xfe,0xe0,0x00,0x73,0xf0,0x7f,0xf8,0x00,0x00,0xe7,0xff,0xff,
0xfb,0xe0,0x00,0x60,0x0f,0x80,0x07,0x00,0x00,0x08,0x0f,0x80,0x00,0x00,0x00,
0x1f,0xff,0xf8,0x3b,0xe0,0x00,0x67,0xff,0xf8,0x38,0x60,0x00,0xe7,0xff,0xff,
0xfb,0x80,0x00,0x60,0x00,0x07,0xc7,0x00,0x00,0x00,0x00,0x07,0xc0,0x00,0x00,
0x17,0xff,0xf8,0x7c,0xe0,0x00,0xcf,0xff,0xf8,0x7c,0xe0,0x00,0xe7,0xcf,0xff,
0xff,0x00,0x00,0xc0,0x30,0x07,0x80,0x00,0x00,0x00,0x30,0x07,0x80,0x00,0x00,
0x07,0xff,0xf8,0x3c,0xe0,0x00,0x9f,0xff,0xf8,0x3d,0xe0,0x00,0xe7,0x87,0xff,
0xff,0x00,0x00,0x80,0x78,0x07,0xc1,0x00,0x00,0x00,0x78,0x07,0xc0,0x00,0x00,
0x07,0xff,0xf8,0x3c,0xe0,0x00,0x9f,0xff,0xf8,0x3d,0xe0,0x00,0xe7,0x87,0xff,
0xff,0x00,0x00,0x80,0x78,0x07,0xc1,0x00,0x00,0x00,0x78,0x07,0xc0,0x00,0x00,
0x87,0xff,0xfa,0x18,0xe0,0x00,0x1f,0xff,0xfa,0x1a,0xe0,0x00,0xe7,0x0f,0xff,
0xfb,0x00,0x00,0x80,0xf0,0x05,0xe6,0x00,0x00,0x00,0xf0,0x05,0xe0,0x00,0x00,
0x3b,0xff,0xff,0x18,0xa0,0x00,0x1f,0xff,0xff,0x1e,0xe0,0x00,0xe7,0x0d,0xff,
0xfb,0x00,0x00,0xa0,0xf2,0x00,0xe7,0x00,0x00,0x00,0xf2,0x00,0xe0,0x00,0x00,
0xfb,0xff,0xe0,0x1d,0x20,0x00,0x9f,0xff,0xe0,0x1f,0xe0,0x00,0x77,0x00,0xff,
0xfa,0x00,0x00,0xe0,0xff,0x1f,0xe7,0x00,0x00,0x00,0xff,0x1f,0xe0,0x00,0x00,
0x5f,0xff,0xe0,0x1a,0x40,0x00,0x0b,0xff,0xe0,0x1a,0x80,0x00,0x67,0x00,0x7f,
0xfe,0x00,0x00,0x70,0xff,0x9f,0xe3,0x00,0x00,0x00,0xff,0x9f,0xe0,0x00,0x00,
0x07,0xff,0xe0,0x37,0xc0,0x00,0x0b,0xff,0xe0,0x3d,0x00,0x00,0x7f,0x80,0xff,
0xf6,0x00,0x00,0x70,0x7f,0x1f,0xce,0x00,0x00,0x00,0x7f,0x1f,0xc0,0x00,0x00,
0x0b,0xff,0xff,0xe5,0xc0,0x00,0x4f,0xff,0xff,0xe6,0x40,0x00,0x3f,0xfd,0xff,
0xec,0x00,0x00,0x70,0x02,0x00,0x16,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,
0x17,0xff,0xff,0xef,0x00,0x00,0x1f,0xff,0xff,0xea,0x00,0x00,0x27,0xff,0xff,
0xfc,0x00,0x00,0x38,0x00,0x00,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,
0x1f,0xff,0xff,0xd6,0x80,0x00,0x3b,0xff,0xff,0xdc,0x80,0x00,0x03,0xff,0xff,
0xfc,0x00,0x00,0x3c,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,
0x01,0x3f,0xff,0x2d,0x00,0x00,0x1d,0x3f,0xff,0x30,0x00,0x00,0x01,0x3f,0xff,
0x70,0x00,0x00,0x1e,0xc0,0x00,0xf8,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,
0x00,0x6f,0xfe,0xdc,0x00,0x00,0x0e,0x0f,0xff,0x60,0x00,0x00,0x00,0x0f,0xfe,
0xe0,0x00,0x00,0x0f,0xf0,0x01,0xf0,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,
0x03,0x40,0xee,0xf8,0x00,0x00,0x04,0x3c,0xe5,0xa0,0x00,0x00,0x00,0x00,0xe3,
0xe0,0x00,0x00,0x07,0xff,0x1f,0xc0,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,
0x02,0x08,0xe1,0x70,0x00,0x00,0x00,0x18,0x0e,0xc0,0x00,0x00,0x00,0x07,0xff,
0x00,0x00,0x00,0x03,0xff,0xef,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,
0x00,0xf2,0x95,0xf0,0x00,0x00,0x00,0xf6,0x05,0x00,0x00,0x00,0x00,0xf1,0xf8,
0x00,0x00,0x00,0x01,0x0f,0x9e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xf3,0xf9,0xe0,0x00,0x00,0x00,0xfc,0xfe,0x20,0x00,0x00,0x00,0xff,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x2f,0xf2,0x80,0x00,0x00,0x00,0x39,0xfd,0x80,0x00,0x00,0x00,0x3e,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x03,0xfc,0x00,0x00,0x00,0x00,0x05,0xfc,0x00,0x00,0x00,0x00,0x06,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 };
//endif
