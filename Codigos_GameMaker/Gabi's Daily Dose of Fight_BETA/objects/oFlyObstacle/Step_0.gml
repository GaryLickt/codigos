speed = oSpawner.run

depth = -y;

y = startY + (sin(current_time/500) * waveHeight)

if instance_exists(ray) {
ray.x = x;
ray.y = y;


if oControl.yay == true {
ray.image_alpha -= 0.05;
}

if ray.image_alpha <= 0 {
instance_destroy(ray);
}
}