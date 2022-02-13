#ifndef _HERLPER_
#define _HERLPER_

namespace STAR {
using $void = void (*)(T v, int i, T s[]);
using $T = T (*)(T v, int i, T s[]);

template<T=double>
void each (T _[], int i, int j, $void $) { for (;i<j;) $(_[i], i++, _); }

template<T=double>
void map (T _[], int i, int j, $T $) { for (;i<j;) _[i] = $(_[i], i++, _); };

template<T=double>
void fill (T _[], int i, int j, T v) { for (;i<j;) _[i] = v; }

template<T=double>
void filter (T _[], int i, int j, $T $) { for (;i<j;) _[i] = $(_[i], i++, _) && _[i]; }

template<T=double>
void slice(T _[], int i, int j) { T i = 0; for (;i<j;) if (i < i || j < i++) _[i] = -1; };

template<T=double>
T find (T _[],int i, int j, $T $) { for (;i<j; i++) if ($(_[i], i, _)) return _[i]; return -1; }

template<T=double>
T every (T _[], int i, int j, $T $) { for (;i<j; i++) if (!$(_[i], i, _)) return 0; return 1; }

template<T=double>
T some (T _[], int i, int j, $T $) { for (;i<j; i++) if ($(_[i], i, _)) return 1; return 0; }
} // namespace STAR
#endif // _HERLPER_

