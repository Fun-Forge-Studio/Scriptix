-- matrix.lua
local Matrix = {}
Matrix.__index = Matrix

function Matrix.new()
    return setmetatable({
        m = {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        }
    }, Matrix)
end

function Matrix:translate(tx, ty, tz)
    local translation = Matrix.new()
    translation.m[1][4] = tx
    translation.m[2][4] = ty
    translation.m[3][4] = tz
    return self:multiply(translation)
end

function Matrix:multiply(other)
    local result = Matrix.new()
    for i = 1, 4 do
        for j = 1, 4 do
            result.m[i][j] = 0
            for k = 1, 4 do
                result.m[i][j] = result.m[i][j] + self.m[i][k] * other.m[k][j]
            end
        end
    end
    return result
end

return Matrix
