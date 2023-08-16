/// @description Insert description here
// You can write your code in this editor
image_xscale -= spd;
image_yscale -= spd;

image_alpha -= spd;

if (image_xscale <= 0) and (image_yscale <= 0) {
instance_destroy();
}