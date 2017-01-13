#pragma once
#include "tile.h"
 const int level[] ={
	22, 23, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 166, 167, 166, 167, 166, 167, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 182, 183, 182, 183, 182, 183, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 166, 167, 114, 115, 166, 167, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 182, 183, 130, 131, 182, 183, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 166, 167, 166, 167, 166, 167, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 182, 183, 182, 183, 182, 183, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 166, 167, 166, 167, 166, 167, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 182, 183, 182, 183, 182, 183, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 114, 115, 0, 0, 0, 0, 0, 0,
	0, 0, 166, 167, 114, 115, 166, 167, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 130, 131, 0, 0, 0, 0, 0, 0,
	0, 0, 182, 183, 130, 131, 182, 183, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 166, 167, 166, 167, 166, 167, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 23,
	0, 0, 182, 183, 182, 183, 182, 183, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 39,
};

 const int level0[] = {
	124, 109, 109, 125, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 124, 109, 109, 125, 118, 118, 118, 118,
	109, 109, 109, 109, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 109, 109, 109, 109, 118, 118, 118, 118,
	109, 109, 109, 109, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 109, 109, 109, 109, 118, 118, 118, 118,
	140, 109, 109, 141, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 140, 109, 109, 141, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 122, 123, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 138, 139, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 120, 121, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 136, 137, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 120, 121, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 136, 137, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 118, 118, 70, 71, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 118, 118, 55, 55, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 118, 118, 55, 55, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 118, 118, 86, 87, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 124, 109, 109, 125,
	118, 118, 118, 120, 121, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 109, 109, 109, 109,
	118, 118, 118, 136, 137, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 109, 109, 109, 109,
	118, 118, 118, 101, 101, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 140, 109, 109, 141,
};


 const int level1[] = {
	 124, 109, 109, 125, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 124, 109, 109, 125,
	 109, 109, 109, 109, 118, 118, 118, 118, 118, 118, 118, 118, 118, 120, 121, 118, 118, 118, 118, 118, 118, 120, 121, 118, 118, 109, 109, 109, 109,
	 109, 109, 109, 109, 118, 118, 118, 118, 118, 118, 118, 118, 118, 136, 137, 118, 118, 118, 118, 118, 118, 136, 137, 118, 118, 109, 109, 109, 109,
	 140, 109, 109, 141, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 140, 109, 109, 141,
	 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118,
	 118, 118, 118, 118, 118, 118, 118, 118, 120, 121, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 112,
	 118, 118, 118, 118, 118, 118, 118, 118, 136, 137, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 112, 112,
	 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 112, 112, 112,
	 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 112, 112, 112, 112, 112,
	 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 112, 112, 112, 112, 112, 112, 112,
	 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
	 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
	 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
	 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
	 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 114, 115, 112, 112, 112, 112, 112, 112,
	 118, 118, 118, 118, 118, 118, 118, 118, 118, 112, 112, 114, 115, 112, 112, 112, 112, 112, 112, 112, 112, 130, 131, 112, 112, 112, 112, 112, 112,
	 118, 118, 118, 118, 118, 118, 118, 118, 112, 112, 112, 130, 131, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
	 118, 118, 118, 118, 118, 118, 118, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
	 118, 118, 118, 118, 118, 118, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 124, 109, 109, 125,
	 118, 118, 118, 118, 118, 112, 112, 112, 112, 112, 112, 114, 115, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 109, 109, 109, 109,
	 118, 118, 118, 112, 112, 112, 112, 112, 112, 112, 112, 130, 131, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 109, 109, 109, 109,
	 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 140, 109, 109, 141,
 };
//TileMap map;
//TileMap map1;