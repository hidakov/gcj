Horse = Struct.new(:initial_position, :maximum_speed)

def solve(d, horses)
  init = (d - horses[0].initial_position) / horses[0].maximum_speed.to_f
  max_time = horses.reduce(init) do|accum, h|
    t = (d - h.initial_position) / h.maximum_speed.to_f
    accum = t if t > accum
    accum
  end

  speed = d / max_time
  sprintf("%.6f", speed)
end

n_cases = STDIN.gets.chomp.to_i
n_cases.times do |i|
  d, n = STDIN.gets.chomp.split(' ').map(&:to_i)
  horses = n.times.reduce([]) do |accum, i|
    k, s = STDIN.gets.chomp.split(' ').map(&:to_i)
    accum + [Horse.new(k, s)]
  end

  ans = solve(d, horses)
  puts "Case ##{i+1}: #{ans}"
end
