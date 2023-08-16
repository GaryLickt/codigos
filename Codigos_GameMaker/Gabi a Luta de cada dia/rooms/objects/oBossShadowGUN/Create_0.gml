/// @description Insert description here
// You can write your code in this editor
var _dy = floor(image_angle/90);
rob = instance_create_depth(x,y,depth+1,oBossShadowTarget);
rob.image_angle = image_angle;
rob.image_xscale = room_width;

switch(_dy){
	case 0: image_yscale = 1;break;
	case 1: image_yscale = -1;break;
	case 2: image_yscale = -1;break;
	case 3: image_yscale = 1;break;
}

