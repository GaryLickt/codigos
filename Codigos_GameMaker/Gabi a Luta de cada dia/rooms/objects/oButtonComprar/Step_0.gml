/// @description Insert description here
// You can write your code in this editor
if place_meeting(x,y,oMouseCollision){
image_xscale = lerp(image_xscale,1.2,0.05);
image_yscale = lerp(image_yscale,1.2,0.05);
image_alpha = lerp(image_alpha,1,0.05);
}else{
image_xscale = lerp(image_xscale,1,0.05);
image_yscale = lerp(image_yscale,1,0.05);
image_alpha = lerp(image_alpha,0.8,0.05);
}