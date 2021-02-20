void BramasTower(int n, char src, char dst, char temp)
{
	if (n > 0){
		MoveTower(n-1, src, temp, dst);
		moveSingleDisk(src, dst);
		movetower(n-1, temp, dest, src);
	}
}


