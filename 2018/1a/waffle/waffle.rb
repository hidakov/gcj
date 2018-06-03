require 'ostruct'

def solve(matrix, r, c, h, v)
  rowsums = []
  matrix.each do |row|
    rowsum = row.reduce(0) do |accum, cell|
      accum += cell
      accum
    end
    rowsums << rowsum
  end
  result1 = cut(rowsums, h)
  return 'IMPOSSIBLE' unless result1.possible

  idx = 0
  range_array = []
  result1.cut_positions.each do |pos|
    range_array << (idx..pos)
    idx = pos + 1
  end
  range_array << (idx..(r-1))

  possible = true
  prev_positions = nil
  range_array.each do |range|
    sub_matrix = matrix[range]
    nrows = range.size
    colsums = []
    (0..(c-1)).each do |j|
      colsum = (0..(nrows-1)).reduce(0) do |accum, i|
        accum += sub_matrix[i][j]
        accum
      end
      colsums << colsum
    end
    res = cut(colsums, v)
    puts "#{res.possible}"
    puts "#{prev_positions}"
    puts "#{res.cut_positions}" 
    if res.possible and (prev_positions.nil? or prev_positions == res.cut_positions)
      prev_positions = res.cut_positions
      next
    else
      possible = false
      break
    end
  end

  if possible
    'POSSIBLE'
  else
    'IMPOSSIBLE'
  end
end

def cut(arr, n_cuts)
  total_chips = arr.reduce(0) do |accum, x|
    accum += x
    accum
  end
  return OpenStruct.new(total_chips: total_chips, possible: false, cut_positions: nil, return_postion: 1) unless total_chips % (n_cuts + 1)

  target = total_chips / (n_cuts + 1)
  cut_positions = []
  cuts_counter = 0
  sum = 0
  idx = 0
  max_idx = arr.size - 1
  while idx < max_idx 
    break if cuts_counter >= n_cuts

    x = arr[idx]
    sum += x  
    if sum > target
      return OpenStruct.new(total_chips: total_chips, possible: false, cut_positions: nil, return_postion: 2)
    elsif sum == target
      cut_positions << idx
      cuts_counter += 1 
      sum = 0
    end
    idx += 1
  end
  return OpenStruct.new(total_chips: total_chips, possible: false, cut_positions: nil, return_postion: 3) if cuts_counter < n_cuts

  sum = arr[idx..max_idx].reduce(0) do |accum, x|
    accum += x
    accum
  end
  return OpenStruct.new(total_chips: total_chips, possible: sum == target, cut_positions: cut_positions, return_postion: 4)
end

n_cases = STDIN.gets.chomp.to_i
n_cases.times do |i|
  r, c, h, v = STDIN.gets.chomp.split(' ').map(&:to_i)
  matrix = []
  r.times do
    matrix << STDIN.gets.chomp.split('').map do |ch|
      if ch == '@' 
        1
      else
        0
      end
    end
  end

  ans = solve(matrix, r, c, h, v)
  puts "Case ##{i+1}: #{ans}"
end
