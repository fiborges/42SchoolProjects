
template <typename T>
int easyfind(T container, int tofind)
{
	typename T::iterator foundPosition;

	foundPosition = std::find(container.begin(), container.end(), tofind);
	if (foundPosition == container.end())
		throw std::exception();
	return (std::distance(container.begin(), foundPosition));
}