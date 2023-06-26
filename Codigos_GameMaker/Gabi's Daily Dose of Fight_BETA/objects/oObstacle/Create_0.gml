/// @description Insert description here
// You can write your code in this editor
randomize()
criado = true

switch(global.level){
case 1:sprite_index = spr_obs;image_index = irandom_range(0,image_number-1);break;
case 2:sprite_index = spr_obs2;image_index = irandom_range(0,image_number-1);break;
case 3:sprite_index = spr_obs;image_index = irandom_range(0,image_number-1);break;
case 4:sprite_index = spr_obs;image_index = irandom_range(0,image_number-1);break;
case 5:sprite_index = spr_obs;image_index = irandom_range(0,image_number-1);break;
}