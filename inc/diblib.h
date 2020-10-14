/*
	diblib.h

	This file define the application interface for BITMAP READER.

	Copyright (c) 2020 Takeshi Ishikawa
	This file is part of the BITMAP READER and is licensed under the MIT license.
	For conditions of distribution and use, see the accompanying LICENSE file.
*/

#ifndef DIBLIB_INCLUDE_H
#define DIBLIB_INCLUDE_H

#include <string>

namespace DIBLIB
{
	enum {DIBLIB_RGB, DIBLIB_RLE8, DIBLIB_RLE4, DIBLIB_BITFIELDS, DIBLIB_JPEG, DIBLIB_PNG};

	class WORD
	{
	public:
		WORD();

		unsigned short get() const;
		void set(unsigned short word);
		void swap();
		char getByte1();
		char getByte2();
	private:
		unsigned char byte1;
		unsigned char byte2;
	};

	class DWORD
	{
	public:
		DWORD();

		unsigned long get() const;
		void set(unsigned long dword);
		void swap();
		char getByte1();
		char getByte2();
		char getByte3();
		char getByte4();
	private:
		unsigned char byte1;
		unsigned char byte2;
		unsigned char byte3;
		unsigned char byte4;
	};

	class RGBQUAD
	{
	public:
		RGBQUAD();

		void print();

	private:
		unsigned char rgbBlue;
		unsigned char rgbGreen;
		unsigned char rgbRed;
		unsigned char rgbReserved;
	};

	class BITMAPFILEHEADER
	{
	public:
		void print();
		void swap();

		DWORD getBfSize();
		DWORD getBfOffBits();

	private:
		WORD bfType;
		DWORD bfSize;
		WORD bfReserved1;
		WORD bfReserved2;
		DWORD bfOffBits;
	};

	class BITMAPINFOHEADER
	{
	public:
		void print();
		void swap();

		DWORD getBiSize();
		DWORD getBiWidth();
		DWORD getBiHeight();
		WORD getBiBitCount();
		DWORD getBiCompression();
		DWORD getBiSizeImage();

	private:
		DWORD biSize;
		DWORD biWidth;
		DWORD biHeight;
		WORD biPlanes;
		WORD biBitCount;
		DWORD biCompression;
		DWORD biSizeImage;
		DWORD biXPelsPerMeter;
		DWORD biYPelsPerMeter;
		DWORD biClrUsed;
		DWORD biClrImportant;
	};
}

class DIB
{
public:
	DIB();
	~DIB();

	void loadFile(std::string filename, int swap);
	void release();
	void printDump();
	void printColorIndexDump();

	unsigned long getWidth();
	unsigned long getHeight();
	unsigned char *getColorIndex();
	unsigned long getColorTableSize();
	unsigned long getColorIndexSize();

private:
	DIBLIB::BITMAPFILEHEADER bmfHeader;
	DIBLIB::BITMAPINFOHEADER bmiHeader;
	DIBLIB::RGBQUAD *bmiColors;
	unsigned long colorTableSize;
	unsigned long colorIndexSize;
	unsigned char *colorIndex;
};

#endif