/// @description Insert description here
// You can write your code in this editor
var backid = layer_get_id("Background");
var back2id = layer_get_id("Backgrounds_1");
var back3id = layer_get_id("Backgrounds_2");

var layid = layer_background_get_id(backid);
var lay2id = layer_background_get_id(back2id);
var lay3id = layer_background_get_id(back3id);
veloc = ((oSpawner.runcenario)*-1);
veloc2 = ((oSpawner.runcenario2)*-1);

switch(global.level){
case 1: layer_background_change(layid,spr_background1);layer_background_change(lay2id,spr_background1_2);layer_background_change(lay3id,spr_background1_3);break;
case 2: layer_background_change(layid,spr_background2);layer_background_change(lay2id,spr_background2_2);layer_background_change(lay3id,spr_background2_3);break;
case 3: layer_background_change(layid,spr_background1);break;
case 4: layer_background_change(layid,spr_background1);break;
case 5: layer_background_change(layid,spr_background1);break;
}