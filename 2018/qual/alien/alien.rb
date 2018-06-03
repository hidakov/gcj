class Instructions
  attr_reader :damage, :n_shoot, :n_charge

  def initialize(instructions)
    @instructions = instructions
    @size = instructions.size
    update!
  end

  def swap_rightmost_cs!
    i = @size - 1
    while i > 0 do
      right = @instructions[i].dup
      left = @instructions[i-1].dup
      if right == 'S' and left == 'C'
        @instructions[i] = left 
        @instructions[i-1] = right
        update!
        break
      end
      i -= 1
    end
  end

  private
  def update!
    damage = 0
    n_shoot = 0
    n_charge = 0
    strength = 1
    @instructions.each do |i|
      case i
      when 'C'
        strength *= 2
        n_charge += 1
      when 'S' 
        damage += strength
        n_shoot += 1
      end
    end
  
    @damage = damage
    @n_shoot = n_shoot
    @n_charge = n_charge
  end
end

def solve(durability, instructions)
  obj = Instructions.new(instructions)
  return 'IMPOSSIBLE' if obj.n_shoot > durability

  cnt = 0
  while obj.damage > durability
    obj.swap_rightmost_cs!
    cnt += 1
  end

  cnt
end

n_cases = STDIN.gets.chomp.to_i
n_cases.times do |i|
  d, s = STDIN.gets.chomp.split(' ')
  instructions = s.split('')

  ans = solve(d.to_i, instructions)
  puts "Case ##{i+1}: #{ans}"
end
