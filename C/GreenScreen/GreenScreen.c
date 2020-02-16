
/**
* Normand Bourque
* CIS 205 – L1
* Lab 4
*
* Converts a green screen image and background into one image
*/

/*
This program reads a bitmap file (assumes 24 bit, but with a minor change
it can be used with 32 bit) and converts it to grayscale

file names for input and output are specified on the commandline at run time
    >>./a.out filein.bmp fileout.bmp

The bitmap structure represents the file data. This structure is comprised
of a file header strutucture, a bitmap info header, a color table and padding,
and lastly image data. the read_bitmap function will load a bitmap into these
structures and return a bitmap structure.

once a bitmap structure is constructed it can be write to a file using the
write_bitmap function

In this example program the bitmap is loaded and verified. if no errors occur,
then each pixel is examined. the r g and b values of each pixel are averaged
and each member data of the pixel is asisgned the avg value

*/

#include <stdio.h>
#include <stdlib.h>

//---------TYPEDEF-----------

typedef struct header HEADER; //bitmap file header
typedef struct info INFO; //bitmap image info header

typedef struct bitmap BITMAP;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

//uncomment pixel_32 type def and comment pixel_24 to use 32 bit
//typedef struct pixel_32 PIXEL; //Pixel if using 32 bit bmp
typedef struct pixel_24 PIXEL; //pixel if using 24 bit bmp

//-------END TYPEDEF---------

//--------STRUCTURES--------

struct bitmap
{
    HEADER* header; //bitmap file header
    INFO* info; //bitmap image info header
    BYTE* extra; //color table, padding, etc
    PIXEL* data; //image data
};

#pragma pack(push, 1)
struct header //14 bytes - info aabout the file
{
    WORD signature; //BM for bitmap
    DWORD file_size; //Size of the entire BMP file
    WORD reserved1;  //reserved; must be 0
    WORD reserved2;  //reserved; must be 0
    DWORD offset; //the location of the image data
};
#pragma pack(pop)

#pragma pack(push, 1)
struct info //40 bytes - info about the image
{
    DWORD struct_size; //size of this struct - 40 bytes
    DWORD width;//width of the image
    DWORD height;//height of the image
    WORD planes;//layers in image
    WORD bitcount;//number of bits per pixel
    DWORD compression;///spcifies the type of compression
    DWORD img_size;  //size of image in bytes
    DWORD x_pixels_meter; //number of pixels per meter in x axis
    DWORD y_pixels_meter; //number of pixels per meter in y axis
    DWORD colors_used; //number of colors used in the bitmap
    DWORD important_colors; //number of important colors
};
#pragma pack(pop)

#pragma pack(push, 1)
struct pixel_24  //24 bit pixel,
{
    BYTE blue;
    BYTE green;
    BYTE red;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct pixel_32 //32 bit pixel
{
    BYTE alpha; //only for 32 bit bmp
    BYTE blue;
    BYTE green;
    BYTE red;
};
#pragma pack(pop)

//-------END STRUCTURES-----

//-------PROTOTYPES----
BITMAP* read_bitmap(char* file);
void write_bitmap(char* file, BITMAP* bitmap);
//----END PROTOTYPES---


int main(int argc, char** argv)
{
    //pointer used for background bit map.
    BITMAP* bmp = NULL;
    //pointer used for green screen bit map.
    BITMAP* gbmp = NULL;
    //used for names.
    char* in_file_name;
    char* in_green_screen;
    char* out_file_name;
    int error = 0;

    //test for input
    if(argc == 3)
    {
        puts("ERROR: Program Input");
        error = 1;
    }
    else
    { //get the file names from the command line
        in_file_name = argv[1];
        in_green_screen = argv[2];
        out_file_name = argv[3];
    }

    //file names ok, validate bmp type
    if(error == 0)
    {
        //reads in bits into structs of bitmap.
        bmp = read_bitmap(in_file_name);
        gbmp = read_bitmap(in_green_screen);

        if(bmp == NULL || gbmp == NULL)
        {
            error = 1;
            puts("ERROR: Loading File");
        }
    }

    if(error == 0)
    {
        //things look ok
        //Visit Every Pixel
        int i;
        //used to adjust level of "green screen trying to filter out white"
        int green = 245;
        int blue = 255;
        int red = 255;
        int num_pixels = bmp->info->width * bmp->info->height;

        for(i=0; i<num_pixels;i++)
        {
            //create a pixel pointer at
            PIXEL* p;
            PIXEL* gp;
            //sets pointers to same postion in bit map
            p = (bmp->data + i);
            gp = (gbmp->data + i);
            //copies the colors of the greenscreen from the first pixel of green pixels.
            if(gp->green >= green && gp->blue < blue && gp->red < red)
            {
                (gp->blue) = (p->blue);
                (gp->green) = (p->green);
                (gp->red) = (p->red);
            }

    }

    //write the bmp to a file
    write_bitmap(out_file_name, gbmp);
  }

  return 0;
}

//-----FUNCTIONS----

/**
* loads a bitmap file into memory
* pre: a c string representing a path to the file
* post: a pointer to a BITMAP struct
***/
BITMAP* read_bitmap(char* file)
{
    FILE *in_file = NULL;

    //pointer for bitmap struct
    BITMAP* bmp = malloc(sizeof(BITMAP));

    //initialize bmp struct
    bmp->header = malloc(sizeof(HEADER));
    bmp->info = malloc(sizeof(INFO));
    bmp->extra = NULL;
    bmp->data = NULL;

    int error = 0;

    in_file = fopen(file,"rb");
    if(in_file==NULL)
    {
        puts("ERROR: no input file found");
        error = 1;
    }
    else
    {
        //file exists
        //try reading the header and info header
        fread(bmp->header, sizeof(HEADER), 1, in_file);
        fread(bmp->info, sizeof(INFO), 1, in_file);
    }

    //File loaded and data is bitmap
    if(error == 0)
    {
        //collect everything between the header/info and the img data
        //color table, padding, etc
        int size  = bmp->header->offset - sizeof(HEADER) - sizeof(INFO);
        bmp->extra = malloc(size);
        fread(bmp->extra, size, 1, in_file);

        //collect the actual image data
        bmp->data = malloc(bmp->info->img_size);
        fread(bmp->data, bmp->info->img_size, 1, in_file);

        //PRINT some bitmap info
        puts("--------------");
        puts("BITMAP INFO");
        puts("--------------");
        printf("Name: %s\n", file);
        printf("BitCount:\t%d\n",bmp->info->bitcount);
        printf("Image Size:\t%.2fMB\n",bmp->info->img_size/1000000.0);//B to MB
        printf("Image Width:\t%d\n",bmp->info->width);
        printf("Image Height:\t%d\n",bmp->info->height);
        printf("Image offset:\t%d\n",bmp->header->offset);
        puts("--------------");

    }
    else
    {
        //something went wrong
        //clean up what has been allocated
        //and set bmp (return value) to NULL
        free(bmp->header);
        free(bmp->info);
        free(bmp);
        bmp = NULL;
    }

    //close the file and return bitmap or NULL
    fclose(in_file);
    return bmp;
}


/**
* write a bitmap file into memory
* pre: a c string representing a path to the file and a bitmap struct
*      a file is created if it does not exist.
* post: nothing
***/
void write_bitmap(char* file, BITMAP* bmp)
{

    FILE *out_file;
    //if file does not exist, create it
    out_file = fopen(file,"wb+");

    int size  = bmp->header->offset - sizeof(HEADER) - sizeof(INFO);

    //write all the parts
    fwrite(bmp->header, sizeof(HEADER), 1, out_file);
    fwrite(bmp->info, sizeof(INFO), 1, out_file);
    fwrite(bmp->extra, size, 1, out_file);
    fwrite(bmp->data, bmp->info->img_size, 1, out_file);

    //close the file
    fclose(out_file);
}


/*Documentation Requirements
Name: Normand Bourque
Course: CIS 205-L1-2194
Assignment:Lab 4
Due Date: 5-2-15
Description: Converts a green screened picture and a background into a single picture.
*/

