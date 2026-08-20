
namespace uSTL {

	template<typename T>
	class vector {
	public:
		vector() : data(nullptr), sz(0), cap(0) {}
		~vector() { delete[] data; }
		void push_back(const T& value) {
			if (sz == cap) {
				size_t new_cap = cap == 0 ? 4 : cap * 2;
				T* new_data = new T[new_cap];
				for (size_t i = 0; i < sz; i++) new_data[i] = data[i];
				delete[] data;
				data = new_data;
				cap = new_cap;
			}
			data[sz++] = value;
		}
		T& operator[](const size_t& idx) {
			return;
		}
	private:
		T* data;
		size_t sz;
		size_t cap;


	};
}