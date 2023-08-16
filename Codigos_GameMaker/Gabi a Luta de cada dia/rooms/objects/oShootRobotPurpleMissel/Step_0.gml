/// @description Insert description here
// You can write your code in this editor


depth = -y
speed += 0.05;
image_speed += 0.05;

instance_create_layer(x,y,"Instances",oPurpleRay);

if distance_to_object(oGabiBoss1) <= 10 {
instance_destroy();
instance_create_layer(x, y, "Instances", oBombCollision);
}