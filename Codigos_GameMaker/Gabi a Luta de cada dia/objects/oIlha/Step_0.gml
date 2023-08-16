/// @description Insert description here
// You can write your code in this editor
sombra = 0;
switch(oCamera.stage){
	case 1: sprite_index = spr_ilha1;sombra = spr_ilha1contorno;break;
	case 2: sprite_index = spr_ilha2;sombra = spr_ilha2contorno;break;
	case 3: sprite_index = spr_ilha1;sombra = spr_ilha1contorno;break;
	case 4: sprite_index = spr_ilha1;sombra = spr_ilha1contorno;break;
	case 5: sprite_index = spr_ilha1;sombra = spr_ilha1contorno;break;
}
if oMainControl.level_map[# oCamera.stage-1, 0] >= 1 {
	image_index = oMainControl.level_map[# oCamera.stage-1, 0]-1;
}else{
	image_index = 0;
}

if oMainControl.level_map[# oCamera.stage-1, 0] = 7 {
	image_index = image_number-1;
}

x+= dir;
y+= dir;