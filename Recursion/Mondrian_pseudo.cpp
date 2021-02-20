void DrawMondrian(double x, double y, double w, double h){
	if (w < 0.1 || h < 0.1) return;
	
	FillRectangle(x,y,w,h, RandomColor());
	
	switch(Randominteger(0,2)){
		case 0:
			break;
		case 1:
			double midX = RandomReal(0, w);
			DrawBlackLine(x+midx, y, h);
			DrawMondrian(x,y,midX, h);
			DrawMondrian(X + mi9dX, y , w-midx, h);
			break;
		case 2:
			.
				.
				.
				.
				.
				.
				.
				.
				
	}
}
