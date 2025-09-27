template<class TL, class TR>
constexpr auto circ_add(
	const TL lhs,
	const TR rhs,
	const decltype(lhs + rhs) rmin = 0,
	const decltype(lhs + rhs) rmax = 360) 
{
	auto result = lhs + rhs;
	auto range = rmax - rmin;
	while (result >= rmax) result -= range;
	while (result < rmin) result += range;
	return result;
}

template<class TL, class TR>
constexpr auto circ_sub(
	const TL lhs,
	const TR rhs,
	const decltype(lhs + rhs) rmin = 0,
	const decltype(lhs + rhs) rmax = 360) 
{
	auto result = lhs - rhs;
	auto range = rmax - rmin;
	while (result >= rmax) result -= range;
	while (result < rmin) result += range;
	return result;
}

template<class TL, class TR>
constexpr auto circ_mul(
	const TL lhs,
	const TR rhs,
	const decltype(lhs + rhs) rmin = 0,
	const decltype(lhs + rhs) rmax = 360) 
{
	auto result = lhs - rhs;
	auto range = rmax - rmin;
	while (result >= rmax) result -= range;
	while (result < rmin) result += range;
	return result;
}

template<class TL, class TR>
constexpr auto circ_div(
	const TL lhs,
	const TR rhs,
	const decltype(lhs + rhs) rmin = 0,
	const decltype(lhs + rhs) rmax = 360) 
{
	auto result = lhs - rhs;
	auto range = rmax - rmin;
	while (result >= rmax) result -= range;
	while (result < rmin) result += range;
	return result;
}

template<class TL, class TR>
constexpr auto circ_shortdist(
	const TL lhs,
	const TR rhs,
	const decltype(lhs + rhs) rmin = 0,
	const decltype(lhs + rhs) rmax = 360) 
{
	auto a = circ_sub(rhs, lhs, rmin, rmax);
	auto b = circ_sub(lhs, rhs, rmin, rmax);
	return std::min(a, b);
}

template<class TL, class TR>
constexpr auto circ_shortdiff_signed(
	const TL lhs,
	const TR rhs,
	const decltype(lhs + rhs) rmin = 0,
	const decltype(lhs + rhs) rmax = 360) 
{
	auto a = circ_sub(rhs, lhs, rmin, rmax);
	auto b = circ_sub(lhs, rhs, rmin, rmax);
	if (b > a)
		return a;
	else
		return -b;
}

int main() 
{
	constexpr float a = 20;
	constexpr int b = 340;

	constexpr auto c = circ_shortdiff_signed(b, a);

	return 0;
}