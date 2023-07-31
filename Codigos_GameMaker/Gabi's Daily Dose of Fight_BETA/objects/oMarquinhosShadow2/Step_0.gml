/// @description Insert description here
// You can write your code in this editor
var d = floor(direction/90);

switch(d){
case 0: image_xscale = 1;break;
case 1: image_xscale = -1;break;
case 2: image_xscale = -1;break;
case 3: image_xscale = 1;break;
}
if oBossShadow.stage = 3 {
path_speed = 0;
sprite_index = spr_carshadowbug;
}

if oBossShadow.stage = 4 {
instance_destroy();
}

depth = -y;