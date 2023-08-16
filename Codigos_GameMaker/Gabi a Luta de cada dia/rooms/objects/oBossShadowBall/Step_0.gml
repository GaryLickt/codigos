instance_create_layer(x,y,"Instances",oBlackRay);
if !collision_rectangle( view_xport[0], view_yport[0], view_xport[0] + view_wport[0], view_yport[0] + view_hport[0], id, false, false ) {
instance_destroy();
}