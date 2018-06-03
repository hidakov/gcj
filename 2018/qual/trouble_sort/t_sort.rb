def solve(numbers)
end

n_cases = STDIN.gets.chomp.to_i
n_cases.times do |i|
  n = STDIN.gets.chomp
  numbers = STDIN.gets.chomp.split(' ').map(&:to_i)

  ans = solve(numbers)
  puts "Case ##{i+1}: #{ans}"
end
