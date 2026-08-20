
namespace uSTL {
	template<typename T, size_t N>
	class array {
	public:
		array() = default;

		array(const std::initializer_list<T>& inList) {
			if (inList.size() != N) throw std::length_error("Size mismatch");
			int i = 0;
			for (auto& e : inList) {
				arr[i++] = e;
			}
		}

		/// Element access ///
		
		T& operator[](size_t idx)  {
				return *(arr + idx);
		}

		T& at(size_t idx) {
			if (idx < N)
				return *(arr + idx);
			else
				throw std::out_of_range("Out of bounds");
		}
		
		T& front() {
			return arr[0];
		}

		T& back() {
			return arr[N - 1];
		}

		T* data() {
			if (this) {
				return arr;
			}
			else return nullptr;
		}

		/// Iterators ///

		T* begin() {
			return arr;
		}

		
	private:
		T arr[N];
	};
}

