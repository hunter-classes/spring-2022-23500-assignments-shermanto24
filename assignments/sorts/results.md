<h3> Notes </h3>

I changed the headers of the functions.
- I changed our `qsort` from class to `std::vector<int> bad_qsort(std::vector<int> &list, bool good_pivot)`. I also modified the code in it to accommodate for when good_pivot is true.
- I have the in-place `qsort` as `void in_place_qsort(std::vector<int> &list, int l, int h, bool good_pivot)`. Ivan Rao helped me with the code for this.

<h3> Summary </h3>

When the data set was **randomized**:
- `bad_qsort` with a bad pivot took the **same** amount of time as it did with a good pivot. This was consistent regardless of the size.
- On a small data set (i.e. size of 10,000), `msort` and `bad_qsort` took the same amount of time (regardless of the pivot used for `bad_qsort`).
- On a big data set (i.e. size of 100,000), `bad_qsort` was much slower than `msort` (almost 4 times slower) and this became worse as the size of the data set increased.
- In all these data sets, `in_place_qsort` performed much faster than the other functions regardless of the pivot.

When the data set was **sorted**:
- On a small data set (e.g. size of 10,000), `bad_qsort` with a bad pivot was *significantly slower* than all the other functions as it took about 2 seconds. Although `in_place_qsort` with a bad pivot was also slower than the other functions, it took only around .25 second.
- On a huge data set (i.e. size of 1,000,000), `msort` took almost 5.5 seconds while `in_place_qsort` took only around .1 second.

<h4> In general: </h4>

- For randomized data sets, the pivot did *not* affect the time it took for the `qsorts` to run.
- For sorted data sets, the `qsorts` with a bad pivot were slower than the other functions, with `bad_qsort` being the worst.
- As the size of the data set increases, the time it takes for the sorts to run increases. Also, `msort` performs increasingly slower compared to `in_place_qsort` with a good pivot.
- When the data set was randomized and huge (i.e. size = 1,000,000), `in_place_qsort` with a good pivot performed slightly slower than it did when it was sorted.
- `in_place_qsort` with a good pivot was almost always the fastest out of the three functions.
