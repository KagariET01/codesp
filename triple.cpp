//  TRIPLE

template<typename I>struct triple{
	I x=0,y=1;
	triple(I&a,I&b){
		x=a,y=b;
	} 
	triple&fix(){
		I gcd=__gcd(x,y);
		x=x/gcd;
		y=y/gcd;
		return *this;
	}
	I&operator=(I&b){
		x=b;
		y=1;
		return b;
	}
};

template<typename I>triple<I>operator+(triple<I>&a,I&b){
	a.fix();
	return triple(a.x + a.y*b , a.y);
}

template<typename I>triple<I>operator+(I&b,triple<I>&a){
	a.fix();
	return triple(a.x + a.y*b , a.y);
}

template<typename I>triple<I>operator-(triple<I>&a,I&b){
	a.fix();
	return triple(a.x - a.y*b , a.y);
}

template<typename I>triple<I>operator-(I&b,triple<I>&a){
	a.fix();
	return triple(a.x - a.y*b , a.y);
}

template<typename I>triple<I>operator*(triple<I>&a,I&b){
	a.fix();
	triple<I>re=triple(a.x*b , a.y);
	re.fix();
	return re;
}

template<typename I>triple<I>operator*(I&b,triple<I>&a){
	a.fix();
	triple<I>re=triple(a.x*b , a.y);
	re.fix();
	return re;
}

template<typename I>triple<I>operator/(triple<I>&a,I&b){
	a.fix();
	triple<I>re=triple(a.x , a.y*b);
	re.fix();
	return re;

}

template<typename I>triple<I>operator/(I&b,triple<I>&a){
	a.fix();
	triple<I>re=triple(a.x , a.y*b);
	re.fix();
	return re;
}



template<typename I>triple<I>operator+(triple<I>&a,triple<I>&b){
	a.fix();
	b.fix();
	I gcd=__gcd(a.y,b.y);
	I bx=a.y/gcd;
	I ax=b.y/gcd;
	triple<I>re;
	re.x=a.x*ax + b.x*bx;
	re.y=a.y*ax;
	re.fix();
	return re;
}

template<typename I>triple<I>operator-(triple<I>&a,triple<I>&b){
	a.fix();
	b.fix();
	I gcd=__gcd(a.y,b.y);
	I bx=a.y/gcd;
	I ax=b.y/gcd;
	triple<I>re;
	re.x=a.x*ax - b.x*bx;
	re.y=a.y*ax;
	re.fix();
	return re;
}

template<typename I>triple<I>operator*(triple<I>a,triple<I>&b){
	return triple<I>(
			a.x*b.x,
			a.y*b.y
	)
}

template<typename I>triple<I>operator/(triple<I>a,triple<I>&b){
	return triple<I>(
			a.x*b.y,
			a.y*b.x
	)
}


