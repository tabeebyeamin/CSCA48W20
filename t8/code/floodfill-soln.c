#include<stdio.h>
#include<stdlib.h>

void printImgArray(char array[10][10])
{
 // Print out the contents of the array, it can be
 // used with the original array, or with the labeled
 // output after calling cell_count().
  
 printf("------ Image Contents -------\n");
 for (int i=0; i<10; i++)
 {
   for (int j=0; j<10; j++)
     printf("%c, ",array[i][j]);
   printf("\n");
 }
 printf("-----------------------------\n");
}

void floodFill(char image[10][10], int x, int y, int value, int bound)
{
 // This function takes as input a 2D image array
 // which contains pixel values. 
 //
 // It floodFills (if you haven't tried floodfill,
 // open up a picture editor and use the paint tool!)
 // starting at location (x,y), filling the image
 // with the specified 'value', up to (but not
 // including) the boundary of the shape in the
 // picture, whose colour is given by 'bound'
 //
 // This function should do its work NON-recursively!
  
 // TO DO: Complete this function!

}

void floodFill_R(char image[10][10], int x, int y, char value, char bound)
{
 // This function takes as input a 2D image array
 // which contains pixel values. 
 //
 // It floodFills (if you haven't tried floodfill,
 // open up a picture editor and use the paint tool!)
 // starting at location (x,y), filling the image
 // with the specified 'value', up to (but not
 // including) the boundary of the shape in the
 // picture, whose colour is given by 'bound'
 //
 // This function should do its work recursively!
  
 // TO DO: Complete this function!

    // if not at the boundary, set colour
    if (image[x][y] == bound || image[x][y] == value) return;

    image[x][y] = value;

    // check up
    floodFill_R(image, x, y-1, value, bound);
    // check down
    floodFill_R(image, x, y+1, value, bound);

    // check left
    floodFill_R(image, x-1, y, value, bound);

    // check right
    floodFill_R(image, x+1, y, value, bound);
    

}

int main()
{
  char polyImg[10][10]={{'_','_','_','_','_','_','_','_','_','_'},
		               {'_','_','X','_','_','_','_','X','_','_'},
		               {'_','X','_','X','_','_','X','_','X','_'},
		               {'_','X','_','_','X','_','X','_','X','_'},
		               {'_','_','X','_','X','X','_','_','X','_'},
		               {'_','_','X','_','_','_','_','X','X','_'},
		               {'_','X','_','_','_','X','_','X','_','_'},
		               {'_','_','X','_','X','X','_','_','X','_'},
		               {'_','_','X','X','_','_','X','X','X','_'},
		               {'_','_','_','_','_','_','_','_','_','_'}};
		       
  printImgArray(polyImg);
  floodFill_R(polyImg,5,4,'a','X');
  printImgArray(polyImg);
  
  return 0;
}
