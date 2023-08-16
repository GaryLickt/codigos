/// @description Insert description here
// You can write your code in this editor

speed -= 0.05;

var dir = floor(direction/90);
var way = 0;
switch(dir){
case 0: way = 1;break;
case 1: way = -1;break;
case 2: way = -1;break;
case 3: way = 1;break;
}

image_angle += way;