/// @description Insert description here
// You can write your code in this editor
speed += 0.05;
image_speed += 0.05;

instance_create_layer(x,y,"Instances",oRedRay);

if distance_to_object(oGabiBoss1) <= 10 {
instance_destroy();
instance_create_layer(x, y, "Instances", oBombCollision);
}