/// @description Insert description here
// You can write your code in this editor
randomize()
criado = true

if (global.level = 1) or (room_get_name(room) == "RoomBoss1") {
sprite_index = spr_instrobs;
image_index = irandom_range(0,image_number-1);
}

var dir = floor(point_direction(x,y,oGabiBoss1.x,y)/90)

switch(dir){
case 0: image_xscale = -1;break;
case 1: image_xscale = 1;break;
case 2: image_xscale = 1;break;
case 3: image_xscale = -1;break;
}