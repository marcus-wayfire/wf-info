/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2023 Scott Moreau
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


#pragma once

#include <wayfire/nonstd/json.hpp>
#include <wayfire/plugins/common/input-grab.hpp>
#include <wayfire/plugins/common/shared-core-data.hpp>
#include <wayfire/plugins/ipc/ipc-method-repository.hpp>
#include "ipc-rules-common.hpp"

class wayfire_information
{
    wl_global *manager;

  public:
    wf::pointer_interaction_t *base;
    std::vector<wl_resource*> client_resources;
    void send_view_info(wayfire_view view);
    void deactivate();
    void set_base_ptr(wf::pointer_interaction_t *base);
    wf::wl_idle_call idle_set_cursor;
    std::map<wf::output_t*, std::unique_ptr<wf::input_grab_t>> input_grabs;
    bool ipc_call = false;
    bool wl_call = false;
    wf::json_t ipc_response;
    wf::ipc::method_callback get_view_info_ipc;
    wf::shared_data::ref_ptr_t<wf::ipc::method_repository_t> ipc_repo;
    void end_grab();
    wayfire_information();
    ~wayfire_information();
};
