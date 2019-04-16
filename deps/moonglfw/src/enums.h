/* The MIT License (MIT)
 *
 * Copyright (c) 2019 Stefano Trettel
 *
 * Software repository: MoonGLFW, https://github.com/stetre/moonglfw
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef enumsDEFINED
#define enumsDEFINED

/* enums.c */
#define enums_free_all moonglfw_enums_free_all
void enums_free_all(lua_State *L);
#define enums_test moonglfw_enums_test
uint32_t enums_test(lua_State *L, uint32_t domain, int arg, int *err);
#define enums_check moonglfw_enums_check
uint32_t enums_check(lua_State *L, uint32_t domain, int arg);
#define enums_push moonglfw_enums_push
int enums_push(lua_State *L, uint32_t domain, uint32_t code);
#define enums_values moonglfw_enums_values
int enums_values(lua_State *L, uint32_t domain);
#define enums_checklist moonglfw_enums_checklist
uint32_t* enums_checklist(lua_State *L, uint32_t domain, int arg, uint32_t *count, int *err);
#define enums_freelist moonglfw_enums_freelist
void enums_freelist(lua_State *L, uint32_t *list);


/* Enum domains */
#define DOMAIN_ACTION               0
#define DOMAIN_BUTTON               1
#define DOMAIN_KEY                  2
#define DOMAIN_TARGET               3
#define DOMAIN_API                  4
#define DOMAIN_ROBUSTNESS           5
#define DOMAIN_RELEASE_BEHAVIOR     6
#define DOMAIN_PROFILE              7
#define DOMAIN_INPUT_MODE           8
#define DOMAIN_CURSOR_MODE          9
#define DOMAIN_CURSOR_SHAPE         10

#define testaction(L, arg, err) (uint32_t)enums_test((L), DOMAIN_ACTION, (arg), (err))
#define checkaction(L, arg) (uint32_t)enums_check((L), DOMAIN_ACTION, (arg))
#define pushaction(L, val) enums_push((L), DOMAIN_ACTION, (uint32_t)(val))
#define valuesaction(L) enums_values((L), DOMAIN_ACTION)

#define testbutton(L, arg, err) (uint32_t)enums_test((L), DOMAIN_BUTTON, (arg), (err))
#define checkbutton(L, arg) (uint32_t)enums_check((L), DOMAIN_BUTTON, (arg))
#define pushbutton(L, val) enums_push((L), DOMAIN_BUTTON, (uint32_t)(val))
#define valuesbutton(L) enums_values((L), DOMAIN_BUTTON)

#define testkey(L, arg, err) (uint32_t)enums_test((L), DOMAIN_KEY, (arg), (err))
#define checkkey(L, arg) (uint32_t)enums_check((L), DOMAIN_KEY, (arg))
#define pushkey(L, val) enums_push((L), DOMAIN_KEY, (uint32_t)(val))
#define valueskey(L) enums_values((L), DOMAIN_KEY)

#define testtarget(L, arg, err) (uint32_t)enums_test((L), DOMAIN_TARGET, (arg), (err))
#define checktarget(L, arg) (uint32_t)enums_check((L), DOMAIN_TARGET, (arg))
#define pushtarget(L, val) enums_push((L), DOMAIN_TARGET, (uint32_t)(val))
#define valuestarget(L) enums_values((L), DOMAIN_TARGET)

#define testapi(L, arg, err) (uint32_t)enums_test((L), DOMAIN_API, (arg), (err))
#define checkapi(L, arg) (uint32_t)enums_check((L), DOMAIN_API, (arg))
#define pushapi(L, val) enums_push((L), DOMAIN_API, (uint32_t)(val))
#define valuesapi(L) enums_values((L), DOMAIN_API)

#define testrobustness(L, arg, err) (uint32_t)enums_test((L), DOMAIN_ROBUSTNESS, (arg), (err))
#define checkrobustness(L, arg) (uint32_t)enums_check((L), DOMAIN_ROBUSTNESS, (arg))
#define pushrobustness(L, val) enums_push((L), DOMAIN_ROBUSTNESS, (uint32_t)(val))
#define valuesrobustness(L) enums_values((L), DOMAIN_ROBUSTNESS)

#define testreleasebehavior(L, arg, err) (uint32_t)enums_test((L), DOMAIN_RELEASE_BEHAVIOR, (arg), (err))
#define checkreleasebehavior(L, arg) (uint32_t)enums_check((L), DOMAIN_RELEASE_BEHAVIOR, (arg))
#define pushreleasebehavior(L, val) enums_push((L), DOMAIN_RELEASE_BEHAVIOR, (uint32_t)(val))
#define valuesreleasebehavior(L) enums_values((L), DOMAIN_RELEASE_BEHAVIOR)

#define testprofile(L, arg, err) (uint32_t)enums_test((L), DOMAIN_PROFILE, (arg), (err))
#define checkprofile(L, arg) (uint32_t)enums_check((L), DOMAIN_PROFILE, (arg))
#define pushprofile(L, val) enums_push((L), DOMAIN_PROFILE, (uint32_t)(val))
#define valuesprofile(L) enums_values((L), DOMAIN_PROFILE)

#define testinputmode(L, arg, err) (uint32_t)enums_test((L), DOMAIN_INPUT_MODE, (arg), (err))
#define checkinputmode(L, arg) (uint32_t)enums_check((L), DOMAIN_INPUT_MODE, (arg))
#define pushinputmode(L, val) enums_push((L), DOMAIN_INPUT_MODE, (uint32_t)(val))
#define valuesinputmode(L) enums_values((L), DOMAIN_INPUT_MODE)

#define testcursormode(L, arg, err) (uint32_t)enums_test((L), DOMAIN_CURSOR_MODE, (arg), (err))
#define checkcursormode(L, arg) (uint32_t)enums_check((L), DOMAIN_CURSOR_MODE, (arg))
#define pushcursormode(L, val) enums_push((L), DOMAIN_CURSOR_MODE, (uint32_t)(val))
#define valuescursormode(L) enums_values((L), DOMAIN_CURSOR_MODE)

#define testcursorshape(L, arg, err) (uint32_t)enums_test((L), DOMAIN_CURSOR_SHAPE, (arg), (err))
#define checkcursorshape(L, arg) (uint32_t)enums_check((L), DOMAIN_CURSOR_SHAPE, (arg))
#define pushcursorshape(L, val) enums_push((L), DOMAIN_CURSOR_SHAPE, (uint32_t)(val))
#define valuescursorshape(L) enums_values((L), DOMAIN_CURSOR_SHAPE)

#if 0 /* scaffolding 6yy */
#define testxxx(L, arg, err) (uint32_t)enums_test((L), DOMAIN_XXX, (arg), (err))
#define checkxxx(L, arg) (uint32_t)enums_check((L), DOMAIN_XXX, (arg))
#define pushxxx(L, val) enums_push((L), DOMAIN_XXX, (uint32_t)(val))
#define valuesxxx(L) enums_values((L), DOMAIN_XXX)
    CASE(xxx);

#endif

#endif /* enumsDEFINED */


