export const quicksort = (arr) => {
    if (arr.length === 1 || arr.length === 0) return arr;
    const pivotIndex = Math.floor(arr.length / 2);
    const pivot = arr[pivotIndex];
    let less = [];
    let greater = [];
    _.forEach(arr, (value, i) => {
      if (i === pivotIndex) return;
      if (value <= pivot) less.push(value);
      else greater.push(value);
    });
    less = quicksort(less);
    greater = quicksort(greater);
    return [...less, pivot, ...greater];
};

/*
* This algorithm is O(n + m) where n and m are the sizes of arr1 and arr2 respectively
*/
const mergeSortedArrays = ({ arr1, arr2 }) => {
  if (arr1.length === 0 && arr2.length === 0) return [];
  const total = [];
  let arr1Index = 0;
  let arr2Index = 0;
  while (arr1Index < arr1.length && arr2Index < arr2.length) {
    if (arr1[arr1Index] > arr2[arr2Index]) {
      total.push(arr2[arr2Index]);
      arr2Index +=1;
    } else {
      total.push(arr1[arr1Index]);
      arr1Index += 1;
    }
  }

  if (arr1Index === arr1.length) {
    while (arr2Index < arr2.length) {
      total.push(arr2[arr2Index]);
      arr2Index += 1;
    }
  } else {
    while (arr1Index < arr1.length) {
      total.push(arr1[arr1Index]);
      arr1Index += 1;
    }
  }
  return total;
};

export const mergesort = (fullArr) => {
  if (fullArr.length <= 1) return fullArr;

  let left = fullArr.slice(0, Math.floor(fullArr.length/2));
  let right = fullArr.slice(Math.floor(fullArr.length/2), fullArr.length);

  left = mergesort(left);
  right = mergesort(right);

  return mergeSortedArrays({ arr1: left, arr2: right });
};

/* Timsort coming soon */

/*
  Test Cases
*/
let successes = 0;
const failures = [];
const testArrays = [
  { a: [], expected: [] },
  { a: [1], expected: [1] },
  { a: [9,8,7,6,5,4,3,2,1], expected: [1,2,3,4,5,6,7,8,9] },
  { a: [1,2,3,4,5,6,7,8,9], expected: [1,2,3,4,5,6,7,8,9] },
  { a: [10, 0, -10], expected: [-10, 0, 10] },
  { a: [-9, -10, 10, 9], expected: [-10, -9, 9, 10] },
  { a: [Infinity, 9, Infinity], expected: [9, Infinity, Infinity] },
  { a: [Infinity, 9, 11, 10, -Infinity], expected: [-Infinity, 9, 10, 11, Infinity] }
];
const test = (testArrays) => {
    // quicksort and mergesort
    _.forEach(testArrays, ({ a, expected }) => {
      const mergesortResult = mergesort(a);
      const quicksortResult = quicksort(a);
      if (_.isEqual(mergesortResult, expected)) successes += 1;
      else failures.push(`Mergesort failed: input ${a} output ${mergesortResult} expected ${expected}`);

      if(_.isEqual(quicksortResult, expected)) successes += 1;
      else failures.push(`Quicksort failed: input ${a} output ${quicksortResult} expected ${expected}`)
    });
}
