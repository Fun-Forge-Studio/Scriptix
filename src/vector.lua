-- vector.lua
local Vector = {}
Vector.__index = Vector

function Vector.new(x, y, z)
    return setmetatable({x = x, y = y, z = z}, Vector)
end

function Vector:add(other)
    return Vector.new(self.x + other.x, self.y + other.y, self.z + other.z)
end

function Vector:subtract(other)
    return Vector.new(self.x - other.x, self.y - other.y, self.z - other.z)
end

function Vector:dot(other)
    return self.x * other.x + self.y * other.y + self.z * other.z
end

function Vector:magnitude()
    return math.sqrt(self:dot(self))
end

function Vector:normalize()
    local mag = self:magnitude()
    return Vector.new(self.x / mag, self.y / mag, self.z / mag)
end

return Vector
