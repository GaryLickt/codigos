/// @description Insert description here
// You can write your code in this editor
script_execute(state);

visao = oAllan.visi;

if (state = scr_sasha_chase) and (visao = true) {
state = scr_sasha_choose;
oAllan.detect = false;
}

depth = -y;