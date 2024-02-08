function swap(arr, i, j) {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

function partition(arr, p) {
    let { lb, ub } = p;
    let x = arr[lb];
    let down = lb + 1;
    let up = ub;

    while (down <= up) {
        while (down <= up && arr[down] <= x) {
            down++;
        }
        while (down <= up && arr[up] > x) {
            up--;
        }
        if (down < up) {
            swap(arr, down, up);
            down++;
            up--;
        }
    }
    swap(arr, lb, up);
    return up;
}

function quicksort(arr) {
    let stack = [];
    let p = { lb: 0, ub: arr.length - 1 };
    stack.push(p);

    while (stack.length > 0) {
        p = stack.pop();
        while (p.lb < p.ub) {
            let j = partition(arr, p);
            if (j - p.lb > p.ub - j) {
                stack.push({ lb: p.lb, ub: j - 1 });
                p.lb = j + 1;
            } else {
                stack.push({ lb: j + 1, ub: p.ub });
                p.ub = j - 1;
            }
        }
    }
}

let a = [20, 10, 3, 2, 1, 25, 35, 21, 23, 12, 11, -1, 44, 34, 23, 34, 56, -111, 34, 56];
quicksort(a);

console.log("sorted array:");
console.log(a.join(" "));
