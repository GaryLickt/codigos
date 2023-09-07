/// @description Insert description here
// You can write your code in this editor
if (place_meeting(x,y,oAllan)) and (oControl.cena1 = true) {
oLight.pisca = true;
alarm[1] = choose(6,16,21);
}else{
alarm[0] = 1;
}
