function removeDuplicate(arr)
{
    let dict = {};
    arr.forEach(element => {dict[element + '_' + typeof(element)] = element} )
    return Object.values(dict);
}

let arr = ['a', 'b', 'a', 1, 2, 2, 1]
arr = removeDuplicate(arr);
console.log(arr);