
#ifndef __empty

	#if defined(__GNUC__) || defined(__GNUG__)
		#define __empty int __empty__[0]

	#else
		#define __empty struct __empty__ {};

	#endif

#endif

namespace prime {

	template <class Element>
	struct DefaultLoopCondition {
		__empty;
		inline constexpr bool operator()(Element) {
			return true;
		}
	};

	template <template <class ...> class TList, class Element, class LoopCondition = DefaultLoopCondition<Element>>
	class PrimeGen {

		private:

			typedef TList<Element> List;
			List list;
			Element current;
			LoopCondition loop;

		public:

			struct iterator;

			inline iterator begin() {
				return iterator(this);
			}

			inline iterator end() {
				return iterator(this);
			}

			inline PrimeGen(LoopCondition loop = LoopCondition()) {
				PrimeGen::list = List();
				PrimeGen::loop = loop;
				PrimeGen::current = 3u;
			}

			struct iterator {

				PrimeGen *lp_primegen;

				inline iterator (PrimeGen *pointer) {
					lp_primegen = pointer;
				}

				inline Element operator*() {
					return lp_primegen->current;
				}

				inline constexpr bool operator==(iterator) {
					return !lp_primegen->loop(lp_primegen->current);
				}

				inline constexpr bool operator!=(iterator) {
					return lp_primegen->loop(lp_primegen->current);
				}

				inline void operator++() {
					auto &list = lp_primegen->list;
					auto &current = lp_primegen->current;
					list.push_back(current);
					begin:
					current += 2;
					for (auto divisor : list) {
						if (!(current % divisor)) {
							goto begin;
						}
					}
					return;
				}

			};

	};

}
