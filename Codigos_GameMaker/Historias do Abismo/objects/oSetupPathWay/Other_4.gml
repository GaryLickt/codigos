//CRIE A GRADE
grid = mp_grid_create(0,0,room_width/32,room_height/32,32,32);

//AQUI OS OBJETOS QUE IRAO COLIDIR NA SUA GRID
mp_grid_add_instances(grid,oBarrierParent,true);