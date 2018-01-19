int lcg(int crntx, int amult, int inc, int mod)
{
	return((amult * crntx + inc) % mod);
};
