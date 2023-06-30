/// @description Insert description here
// You can write your code in this editor
image_xscale -= 0.05;
image_yscale -= 0.05;

image_alpha -= 0.05;

if (image_xscale = 0) or (image_yscale = 0){
instance_destroy();
}