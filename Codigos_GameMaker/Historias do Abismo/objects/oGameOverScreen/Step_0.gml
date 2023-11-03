/// @description Insert description here
// You can write your code in this editor
if (revfade = false) and (fade = true) and (image_alpha > 0.8){
image_alpha -= 0.001
}

if (revfade = true) and (fade = false) and (image_alpha < 1){
image_alpha += 0.001
}