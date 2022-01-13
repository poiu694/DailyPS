// type
interface Roman {
  key: string;
  value: string;
}

const intToRoman = (num: number): string => {
  const romanKey: Roman[] = [
    { key: '1000', value: 'M' },
    { key: '900', value: 'CM' },
    { key: '500', value: 'D' },
    { key: '400', value: 'CD' },
    { key: '100', value: 'C' },
    { key: '90', value: 'XC' },
    { key: '50', value: 'L' },
    { key: '40', value: 'XL' },
    { key: '10', value: 'X' },
    { key: '9', value: 'IX' },
    { key: '5', value: 'V' },
    { key: '4', value: 'IV' },
    { key: '1', value: 'I' },
  ];
  romanKey.sort((a: Roman, b: Roman) => parseInt(b.key) - parseInt(a.key));
  let romanInteger: string = '';

  for (const item of romanKey) {
    const numKey: number = parseInt(item.key);
    while (num >= numKey) {
      romanInteger += item.value;
      num -= numKey;
    }
  }
  return romanInteger;
};
