/// @description Insert description here
// You can write your code in this editor
image_angle = point_direction(x,y,oGabiBoss2.x,oGabiBoss2.y);

var _dy = floor(image_angle/90);
rob.image_angle = image_angle;
rob.image_xscale = room_width;
switch(_dy){
	case 0: image_yscale = 1;break;
	case 1: image_yscale = -1;break;
	case 2: image_yscale = -1;break;
	case 3: image_yscale = 1;break;
}

if oBossShadow.stage >= 3 {
	instance_destroy(rob);
instance_destroy();
}
