/// @description Insert description here
// You can write your code in this editor
if criado = true {
while(place_meeting(x,y,oObjectiveOBJ)){
var near = instance_nearest(x,y,oObjectiveOBJ);

instance_destroy(near);
}
criado = false
}