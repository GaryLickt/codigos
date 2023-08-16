/// @description Desafio Distorcido
// You can write your code in this editor
alarm[5] = cock;
with(oGabi){
xscale = random_range(0.5,2)*choose(1,-1,1);
yscale = random_range(0.5,2)*choose(1,-1,1);
color = choose(c_red,c_green,c_blue,c_aqua,c_lime,c_purple,c_olive,c_white);
}

if instance_exists(oBackground){
with(oBackground){
var backid = layer_get_id("Background");
var back2id = layer_get_id("Backgrounds_1");
var back3id = layer_get_id("Backgrounds_2");

var layid = layer_background_get_id(backid);
var lay2id = layer_background_get_id(back2id);
var lay3id = layer_background_get_id(back3id);


layer_background_change(layid,choose(spr_background1,spr_background1sus,spr_background2));
layer_background_change(lay2id,choose(spr_background1_2,spr_background1_2sus,spr_background2_2,spr_menuground3));
layer_background_change(lay3id,choose(spr_background1_3,spr_background1_3sus,spr_background,spr_background2_3));

}
}

if instance_exists(oObstacle){
with(oObstacle){
sprite_index = choose(spr_obs,spr_obs2,spr_obssus);
image_index = irandom_range(0,image_number-1);
color = choose(c_red,c_green,c_blue,c_aqua,c_lime,c_purple,c_olive,c_white);
}
}

if instance_exists(oBigObstacle){
with(oBigObstacle){
sprite_index = choose(spr_bigobs,spr_bigobs2,spr_bigobssus);
image_index = irandom_range(0,image_number-1);
color = choose(c_red,c_green,c_blue,c_aqua,c_lime,c_purple,c_olive,c_white);
}
}
