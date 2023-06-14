speed = oSpawner.run

depth = -y;

y = startY + (sin(current_time/500) * waveHeight)

if instance_exists(ray) {
ray.x = x;
ray.y = y;

if ray.sprite_index = spr_rayoff {
image_index = 0
}else{
image_index = 1
}


if oControl.yay == true {
ray.image_alpha -= 0.05;
}

if ray.image_alpha <= 0 {
instance_destroy(ray);
}
}