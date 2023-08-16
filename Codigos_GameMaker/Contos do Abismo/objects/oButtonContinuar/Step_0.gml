/// @description Insert description here
// You can write your code in this editor
if tem_save = true {
image_index = 0;
}else{
image_index = 1;
}


if place_meeting(x,y,oMouse) and tem_save = true {
image_xscale = lerp(image_xscale,1.2,0.05);
image_yscale = lerp(image_yscale,1.2,0.05);
}else{
image_xscale = lerp(image_xscale,1,0.05);
image_yscale = lerp(image_yscale,1,0.05);
}
