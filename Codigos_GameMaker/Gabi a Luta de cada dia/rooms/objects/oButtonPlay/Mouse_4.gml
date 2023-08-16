/// @description Insert description here
// You can write your code in this editor
if place_meeting(x,y,oMouseCollision){
image_xscale = 0.8;
image_yscale = 0.8;
var trans = instance_create_depth(0,0,-9000,oTransicao);
instance_create_depth(0,room_height,-9000,oTransicaoDown);
trans.sala = RoomSelector;
}