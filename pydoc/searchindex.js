Search.setIndex({docnames:["base_plugin_interface","boolean_function","boolean_influence","core_utils","data_container","dataflow","endpoint","gate","gate_library","gate_library_manager","gate_type","gate_type_component","gate_type_property","graph_algorithm","grouping","gui","gui_plugin_interface","hal_py","index","module","net","netlist","netlist_factory","netlist_simulator","netlist_utils","netlist_writer_manager","path","pin_direction","pin_type","plugin_manager","plugins"],envversion:{"sphinx.domains.c":1,"sphinx.domains.changeset":1,"sphinx.domains.cpp":1,"sphinx.domains.javascript":1,"sphinx.domains.math":2,"sphinx.domains.python":1,"sphinx.domains.rst":1,"sphinx.domains.std":1,"sphinx.ext.intersphinx":1,"sphinx.ext.todo":1,sphinx:55},filenames:["base_plugin_interface.rst","boolean_function.rst","boolean_influence.rst","core_utils.rst","data_container.rst","dataflow.rst","endpoint.rst","gate.rst","gate_library.rst","gate_library_manager.rst","gate_type.rst","gate_type_component.rst","gate_type_property.rst","graph_algorithm.rst","grouping.rst","gui.rst","gui_plugin_interface.rst","hal_py.rst","index.rst","module.rst","net.rst","netlist.rst","netlist_factory.rst","netlist_simulator.rst","netlist_utils.rst","netlist_writer_manager.rst","path.rst","pin_direction.rst","pin_type.rst","plugin_manager.rst","plugins.rst"],objects:{"boolean_influence.BooleanInfluencePlugin":{get_boolean_influences_of_gate:[2,1,1,""],get_name:[2,1,1,""],get_version:[2,1,1,""]},"dataflow.DataflowPlugin":{execute:[5,1,1,""],get_name:[5,1,1,""],get_version:[5,1,1,""],name:[5,2,1,""],version:[5,2,1,""]},"graph_algorithm.GraphAlgorithmPlugin":{get_communities:[13,1,1,""],get_communities_fast_greedy:[13,1,1,""],get_communities_spinglass:[13,1,1,""],get_graph_cut:[13,1,1,""],get_name:[13,1,1,""],get_strongly_connected_components:[13,1,1,""],get_version:[13,1,1,""],name:[13,2,1,""],version:[13,2,1,""]},"hal_gui.GuiApi":{deselect:[15,1,1,""],deselectAllItems:[15,1,1,""],deselectGate:[15,1,1,""],deselectModule:[15,1,1,""],deselectNet:[15,1,1,""],getSelectedGateIds:[15,1,1,""],getSelectedGates:[15,1,1,""],getSelectedItemIds:[15,1,1,""],getSelectedItems:[15,1,1,""],getSelectedModuleIds:[15,1,1,""],getSelectedModules:[15,1,1,""],getSelectedNetIds:[15,1,1,""],getSelectedNets:[15,1,1,""],select:[15,1,1,""],selectGate:[15,1,1,""],selectModule:[15,1,1,""],selectNet:[15,1,1,""]},"hal_py.BasePluginInterface":{get_name:[0,1,1,""],get_version:[0,1,1,""],name:[0,2,1,""],version:[0,2,1,""]},"hal_py.BooleanFunction":{Value:[1,0,1,""],__and__:[1,1,1,""],__call__:[1,1,1,""],__eq__:[1,1,1,""],__iand__:[1,1,1,""],__init__:[1,1,1,""],__invert__:[1,1,1,""],__ior__:[1,1,1,""],__ixor__:[1,1,1,""],__ne__:[1,1,1,""],__or__:[1,1,1,""],__str__:[1,1,1,""],__xor__:[1,1,1,""],evaluate:[1,1,1,""],from_string:[1,3,1,""],get_dnf_clauses:[1,1,1,""],get_truth_table:[1,1,1,""],get_variables:[1,1,1,""],is_constant_one:[1,1,1,""],is_constant_zero:[1,1,1,""],is_dnf:[1,1,1,""],is_empty:[1,1,1,""],optimize:[1,1,1,""],optimize_constants:[1,1,1,""],substitute:[1,1,1,""],to_dnf:[1,1,1,""],variables:[1,2,1,""]},"hal_py.BooleanFunction.Value":{name:[1,2,1,""]},"hal_py.CoreUtils":{get_base_directory:[3,5,1,""],get_binary_directory:[3,5,1,""],get_default_log_directory:[3,5,1,""],get_gate_library_directories:[3,5,1,""],get_library_directory:[3,5,1,""],get_plugin_directories:[3,5,1,""],get_share_directory:[3,5,1,""],get_user_config_directory:[3,5,1,""],get_user_share_directory:[3,5,1,""]},"hal_py.DataContainer":{data:[4,2,1,""],delete_data:[4,1,1,""],get_data:[4,1,1,""],get_data_map:[4,1,1,""],has_data:[4,1,1,""],set_data:[4,1,1,""]},"hal_py.Endpoint":{__init__:[6,1,1,""],gate:[6,2,1,""],get_gate:[6,1,1,""],get_net:[6,1,1,""],get_pin:[6,1,1,""],is_destination:[6,2,1,""],is_destination_pin:[6,1,1,""],is_source:[6,2,1,""],is_source_pin:[6,1,1,""],net:[6,2,1,""],pin:[6,2,1,""]},"hal_py.FFComponent":{async_reset_function:[11,2,1,""],async_set_function:[11,2,1,""],clock_function:[11,2,1,""],get_async_reset_function:[11,1,1,""],get_async_set_function:[11,1,1,""],get_async_set_reset_behavior:[11,1,1,""],get_clock_function:[11,1,1,""],get_next_state_function:[11,1,1,""],is_class_of:[11,3,1,""],next_state_function:[11,2,1,""],set_async_reset_function:[11,1,1,""],set_async_set_function:[11,1,1,""],set_async_set_reset_behavior:[11,1,1,""],set_clock_function:[11,1,1,""],set_next_state_function:[11,1,1,""]},"hal_py.GUIPluginInterface":{exec:[16,1,1,""]},"hal_py.Gate":{add_boolean_function:[7,1,1,""],boolean_functions:[7,2,1,""],data:[7,2,1,""],delete_data:[7,1,1,""],fan_in_nets:[7,2,1,""],fan_out_nets:[7,2,1,""],get_boolean_function:[7,1,1,""],get_boolean_functions:[7,1,1,""],get_data:[7,1,1,""],get_data_map:[7,1,1,""],get_fan_in_endpoint:[7,1,1,""],get_fan_in_endpoints:[7,1,1,""],get_fan_in_net:[7,1,1,""],get_fan_in_nets:[7,1,1,""],get_fan_out_endpoint:[7,1,1,""],get_fan_out_endpoints:[7,1,1,""],get_fan_out_net:[7,1,1,""],get_fan_out_nets:[7,1,1,""],get_grouping:[7,1,1,""],get_id:[7,1,1,""],get_input_pins:[7,1,1,""],get_location:[7,1,1,""],get_location_x:[7,1,1,""],get_location_y:[7,1,1,""],get_module:[7,1,1,""],get_name:[7,1,1,""],get_netlist:[7,1,1,""],get_output_pins:[7,1,1,""],get_predecessor:[7,1,1,""],get_predecessors:[7,1,1,""],get_successor:[7,1,1,""],get_successors:[7,1,1,""],get_type:[7,1,1,""],get_unique_predecessors:[7,1,1,""],get_unique_successors:[7,1,1,""],has_data:[7,1,1,""],has_location:[7,1,1,""],id:[7,2,1,""],input_pins:[7,2,1,""],is_gnd_gate:[7,1,1,""],is_vcc_gate:[7,1,1,""],location:[7,2,1,""],location_x:[7,2,1,""],location_y:[7,2,1,""],mark_gnd_gate:[7,1,1,""],mark_vcc_gate:[7,1,1,""],module:[7,2,1,""],name:[7,2,1,""],netlist:[7,2,1,""],output_pins:[7,2,1,""],predecessors:[7,2,1,""],set_data:[7,1,1,""],set_location:[7,1,1,""],set_location_x:[7,1,1,""],set_location_y:[7,1,1,""],set_name:[7,1,1,""],successors:[7,2,1,""],type:[7,2,1,""],unique_predecessors:[7,2,1,""],unique_successors:[7,2,1,""],unmark_gnd_gate:[7,1,1,""],unmark_vcc_gate:[7,1,1,""]},"hal_py.GateLibrary":{__init__:[8,1,1,""],add_include:[8,1,1,""],contains_gate_type:[8,1,1,""],contains_gate_type_by_name:[8,1,1,""],gate_types:[8,2,1,""],get_gate_type_by_name:[8,1,1,""],get_gate_types:[8,1,1,""],get_gnd_gate_types:[8,1,1,""],get_includes:[8,1,1,""],get_name:[8,1,1,""],get_path:[8,1,1,""],get_vcc_gate_types:[8,1,1,""],gnd_gate_types:[8,2,1,""],includes:[8,2,1,""],mark_gnd_gate_type:[8,1,1,""],mark_vcc_gate_type:[8,1,1,""],name:[8,2,1,""],path:[8,2,1,""],vcc_gate_types:[8,2,1,""]},"hal_py.GateLibraryManager":{get_gate_libraries:[9,5,1,""],get_gate_library:[9,5,1,""],get_gate_library_by_name:[9,5,1,""],load:[9,5,1,""],load_all:[9,5,1,""],save:[9,5,1,""]},"hal_py.GateType":{__init__:[10,1,1,""],add_boolean_function:[10,1,1,""],add_boolean_functions:[10,1,1,""],add_input_pin:[10,1,1,""],add_input_pins:[10,1,1,""],add_output_pin:[10,1,1,""],add_output_pins:[10,1,1,""],add_pin:[10,1,1,""],add_pins:[10,1,1,""],assign_pin_group:[10,1,1,""],assign_pin_type:[10,1,1,""],assign_property:[10,1,1,""],boolean_functions:[10,2,1,""],components:[10,2,1,""],gate_library:[10,2,1,""],get_boolean_function:[10,1,1,""],get_boolean_functions:[10,1,1,""],get_component:[10,1,1,""],get_components:[10,1,1,""],get_gate_library:[10,1,1,""],get_id:[10,1,1,""],get_input_pins:[10,1,1,""],get_name:[10,1,1,""],get_output_pins:[10,1,1,""],get_pin_direction:[10,1,1,""],get_pin_directions:[10,1,1,""],get_pin_group:[10,1,1,""],get_pin_groups:[10,1,1,""],get_pin_of_group_at_index:[10,1,1,""],get_pin_type:[10,1,1,""],get_pin_types:[10,1,1,""],get_pins:[10,1,1,""],get_pins_of_direction:[10,1,1,""],get_pins_of_group:[10,1,1,""],get_pins_of_type:[10,1,1,""],get_properties:[10,1,1,""],has_component_of_type:[10,1,1,""],has_property:[10,1,1,""],id:[10,2,1,""],input_pins:[10,2,1,""],name:[10,2,1,""],output_pins:[10,2,1,""],pin_directions:[10,2,1,""],pin_groups:[10,2,1,""],pin_types:[10,2,1,""],pins:[10,2,1,""],properties:[10,2,1,""]},"hal_py.GateTypeComponent":{ComponentType:[11,0,1,""],components:[11,2,1,""],get_component:[11,1,1,""],get_components:[11,1,1,""],get_type:[11,1,1,""],type:[11,2,1,""]},"hal_py.GateTypeComponent.ComponentType":{name:[11,2,1,""]},"hal_py.GateTypeProperty":{name:[12,2,1,""]},"hal_py.Grouping":{assign_gate:[14,1,1,""],assign_gate_by_id:[14,1,1,""],assign_module:[14,1,1,""],assign_module_by_id:[14,1,1,""],assign_net:[14,1,1,""],assign_net_by_id:[14,1,1,""],contains_gate:[14,1,1,""],contains_gate_by_id:[14,1,1,""],contains_module:[14,1,1,""],contains_module_by_id:[14,1,1,""],contains_net:[14,1,1,""],contains_net_by_id:[14,1,1,""],gate_ids:[14,2,1,""],gates:[14,2,1,""],get_gate_ids:[14,1,1,""],get_gates:[14,1,1,""],get_id:[14,1,1,""],get_module_ids:[14,1,1,""],get_modules:[14,1,1,""],get_name:[14,1,1,""],get_net_ids:[14,1,1,""],get_netlist:[14,1,1,""],get_nets:[14,1,1,""],id:[14,2,1,""],module_ids:[14,2,1,""],modules:[14,2,1,""],name:[14,2,1,""],net_ids:[14,2,1,""],netlist:[14,2,1,""],nets:[14,2,1,""],remove_gate:[14,1,1,""],remove_gate_by_id:[14,1,1,""],remove_module:[14,1,1,""],remove_module_by_id:[14,1,1,""],remove_net:[14,1,1,""],remove_net_by_id:[14,1,1,""],set_name:[14,1,1,""]},"hal_py.HalPath":{__init__:[26,1,1,""],__str__:[26,1,1,""]},"hal_py.InitComponent":{get_init_category:[11,1,1,""],get_init_identifier:[11,1,1,""],init_category:[11,2,1,""],init_identifiers:[11,2,1,""],is_class_of:[11,3,1,""],set_init_category:[11,1,1,""],set_init_identifier:[11,1,1,""]},"hal_py.LUTComponent":{init_ascending:[11,2,1,""],is_class_of:[11,3,1,""],is_init_ascending:[11,1,1,""],set_init_ascending:[11,1,1,""]},"hal_py.LatchComponent":{async_reset_function:[11,2,1,""],async_set_function:[11,2,1,""],data_in_function:[11,2,1,""],enable_function:[11,2,1,""],get_async_reset_function:[11,1,1,""],get_async_set_function:[11,1,1,""],get_async_set_reset_behavior:[11,1,1,""],get_data_in_function:[11,1,1,""],get_enable_function:[11,1,1,""],is_class_of:[11,3,1,""],set_async_reset_function:[11,1,1,""],set_async_set_function:[11,1,1,""],set_async_set_reset_behavior:[11,1,1,""],set_data_in_function:[11,1,1,""],set_enable_function:[11,1,1,""]},"hal_py.Module":{assign_gate:[19,1,1,""],contains_gate:[19,1,1,""],contains_module:[19,1,1,""],data:[19,2,1,""],delete_data:[19,1,1,""],gates:[19,2,1,""],get_data:[19,1,1,""],get_data_map:[19,1,1,""],get_gate_by_id:[19,1,1,""],get_gates:[19,1,1,""],get_grouping:[19,1,1,""],get_id:[19,1,1,""],get_input_nets:[19,1,1,""],get_input_port_name:[19,1,1,""],get_input_port_names:[19,1,1,""],get_input_port_net:[19,1,1,""],get_internal_nets:[19,1,1,""],get_name:[19,1,1,""],get_netlist:[19,1,1,""],get_nets:[19,1,1,""],get_next_input_port_id:[19,1,1,""],get_next_output_port_id:[19,1,1,""],get_output_nets:[19,1,1,""],get_output_port_name:[19,1,1,""],get_output_port_names:[19,1,1,""],get_output_port_net:[19,1,1,""],get_parent_module:[19,1,1,""],get_submodules:[19,1,1,""],get_type:[19,1,1,""],has_data:[19,1,1,""],id:[19,2,1,""],input_nets:[19,2,1,""],input_port_names:[19,2,1,""],internal_nets:[19,2,1,""],is_top_module:[19,1,1,""],name:[19,2,1,""],netlist:[19,2,1,""],nets:[19,2,1,""],next_input_port_id:[19,2,1,""],next_output_port_id:[19,2,1,""],output_nets:[19,2,1,""],output_port_names:[19,2,1,""],parent_module:[19,2,1,""],remove_gate:[19,1,1,""],set_cache_dirty:[19,1,1,""],set_data:[19,1,1,""],set_input_port_name:[19,1,1,""],set_name:[19,1,1,""],set_next_input_port_id:[19,1,1,""],set_next_output_port_id:[19,1,1,""],set_output_port_name:[19,1,1,""],set_parent_module:[19,1,1,""],set_type:[19,1,1,""],submodules:[19,2,1,""],top_module:[19,2,1,""],type:[19,2,1,""]},"hal_py.Net":{add_destination:[20,1,1,""],add_source:[20,1,1,""],data:[20,2,1,""],delete_data:[20,1,1,""],destinations:[20,2,1,""],get_data:[20,1,1,""],get_data_map:[20,1,1,""],get_destinations:[20,1,1,""],get_grouping:[20,1,1,""],get_id:[20,1,1,""],get_name:[20,1,1,""],get_netlist:[20,1,1,""],get_num_of_destinations:[20,1,1,""],get_num_of_sources:[20,1,1,""],get_source:[20,1,1,""],get_sources:[20,1,1,""],has_data:[20,1,1,""],id:[20,2,1,""],is_a_destination:[20,1,1,""],is_a_source:[20,1,1,""],is_global_input_net:[20,1,1,""],is_global_output_net:[20,1,1,""],is_gnd_net:[20,1,1,""],is_unrouted:[20,1,1,""],is_vcc_net:[20,1,1,""],mark_global_input_net:[20,1,1,""],mark_global_output_net:[20,1,1,""],name:[20,2,1,""],netlist:[20,2,1,""],num_of_destinations:[20,2,1,""],num_of_sources:[20,2,1,""],remove_destination:[20,1,1,""],remove_source:[20,1,1,""],set_data:[20,1,1,""],set_name:[20,1,1,""],sources:[20,2,1,""],unmark_global_input_net:[20,1,1,""],unmark_global_output_net:[20,1,1,""]},"hal_py.Netlist":{clear_caches:[21,1,1,""],create_gate:[21,1,1,""],create_grouping:[21,1,1,""],create_module:[21,1,1,""],create_net:[21,1,1,""],delete_gate:[21,1,1,""],delete_grouping:[21,1,1,""],delete_module:[21,1,1,""],delete_net:[21,1,1,""],design_name:[21,2,1,""],device_name:[21,2,1,""],gate_library:[21,2,1,""],gates:[21,2,1,""],get_design_name:[21,1,1,""],get_device_name:[21,1,1,""],get_free_gate_ids:[21,1,1,""],get_free_grouping_ids:[21,1,1,""],get_free_module_ids:[21,1,1,""],get_free_net_ids:[21,1,1,""],get_gate_by_id:[21,1,1,""],get_gate_library:[21,1,1,""],get_gates:[21,1,1,""],get_global_input_nets:[21,1,1,""],get_global_output_nets:[21,1,1,""],get_gnd_gates:[21,1,1,""],get_grouping_by_id:[21,1,1,""],get_groupings:[21,1,1,""],get_id:[21,1,1,""],get_input_filename:[21,1,1,""],get_module_by_id:[21,1,1,""],get_modules:[21,1,1,""],get_net_by_id:[21,1,1,""],get_nets:[21,1,1,""],get_next_gate_id:[21,1,1,""],get_next_grouping_id:[21,1,1,""],get_next_module_id:[21,1,1,""],get_next_net_id:[21,1,1,""],get_top_module:[21,1,1,""],get_unique_gate_id:[21,1,1,""],get_unique_grouping_id:[21,1,1,""],get_unique_module_id:[21,1,1,""],get_unique_net_id:[21,1,1,""],get_used_gate_ids:[21,1,1,""],get_used_grouping_ids:[21,1,1,""],get_used_module_ids:[21,1,1,""],get_used_net_ids:[21,1,1,""],get_vcc_gates:[21,1,1,""],global_input_nets:[21,2,1,""],global_output_nets:[21,2,1,""],gnd_gates:[21,2,1,""],groupings:[21,2,1,""],id:[21,2,1,""],input_filename:[21,2,1,""],is_gate_in_netlist:[21,1,1,""],is_global_input_net:[21,1,1,""],is_global_output_net:[21,1,1,""],is_gnd_gate:[21,1,1,""],is_grouping_in_netlist:[21,1,1,""],is_module_in_netlist:[21,1,1,""],is_net_in_netlist:[21,1,1,""],is_vcc_gate:[21,1,1,""],mark_global_input_net:[21,1,1,""],mark_global_output_net:[21,1,1,""],mark_gnd_gate:[21,1,1,""],mark_vcc_gate:[21,1,1,""],modules:[21,2,1,""],nets:[21,2,1,""],set_design_name:[21,1,1,""],set_device_name:[21,1,1,""],set_free_gate_ids:[21,1,1,""],set_free_grouping_ids:[21,1,1,""],set_free_module_ids:[21,1,1,""],set_free_net_ids:[21,1,1,""],set_id:[21,1,1,""],set_input_filename:[21,1,1,""],set_next_gate_id:[21,1,1,""],set_next_grouping_id:[21,1,1,""],set_next_module_id:[21,1,1,""],set_next_net_id:[21,1,1,""],set_used_gate_ids:[21,1,1,""],set_used_grouping_ids:[21,1,1,""],set_used_module_ids:[21,1,1,""],set_used_net_ids:[21,1,1,""],top_module:[21,2,1,""],unmark_global_input_net:[21,1,1,""],unmark_global_output_net:[21,1,1,""],unmark_gnd_gate:[21,1,1,""],unmark_vcc_gate:[21,1,1,""],vcc_gates:[21,2,1,""]},"hal_py.NetlistFactory":{create_netlist:[22,5,1,""],load_netlist:[22,5,1,""],load_netlists:[22,5,1,""]},"hal_py.NetlistUtils":{copy_netlist:[24,5,1,""],get_common_inputs:[24,5,1,""],get_complex_gate_chain:[24,5,1,""],get_gate_chain:[24,5,1,""],get_nets_at_pins:[24,5,1,""],get_next_gates:[24,5,1,""],get_next_sequential_gates:[24,5,1,""],get_path:[24,5,1,""],get_shortest_path:[24,5,1,""],get_subgraph_function:[24,5,1,""],remove_buffers:[24,5,1,""],remove_unused_lut_endpoints:[24,5,1,""],rename_luts_according_to_function:[24,5,1,""],replace_gate:[24,5,1,""]},"hal_py.NetlistWriterManager":{write:[25,5,1,""]},"hal_py.PinDirection":{name:[27,2,1,""]},"hal_py.PinType":{name:[28,2,1,""]},"hal_py.RAMComponent":{bit_size:[11,2,1,""],get_bit_size:[11,1,1,""],is_class_of:[11,3,1,""],set_bit_size:[11,1,1,""]},"hal_py.RAMPortComponent":{address_group:[11,2,1,""],clock_function:[11,2,1,""],data_group:[11,2,1,""],enable_function:[11,2,1,""],get_address_group:[11,1,1,""],get_clock_function:[11,1,1,""],get_data_group:[11,1,1,""],get_enable_function:[11,1,1,""],is_class_of:[11,3,1,""],is_write_port:[11,1,1,""],set_address_group:[11,1,1,""],set_clock_function:[11,1,1,""],set_data_group:[11,1,1,""],set_enable_function:[11,1,1,""],set_write_port:[11,1,1,""],write_port:[11,2,1,""]},"hal_py.StateComponent":{get_neg_state_identifier:[11,1,1,""],get_state_identifier:[11,1,1,""],is_class_of:[11,3,1,""],neg_state_identifier:[11,2,1,""],set_neg_state_identifier:[11,1,1,""],set_state_identifier:[11,1,1,""],state_identifier:[11,2,1,""]},"hal_py.plugin_manager":{get_plugin_instance:[29,5,1,""],get_plugin_names:[29,5,1,""],load:[29,5,1,""],load_all_plugins:[29,5,1,""],unload:[29,5,1,""],unload_all_plugins:[29,5,1,""]},"netlist_simulator.Event":{__eq__:[23,1,1,""],__init__:[23,1,1,""],__lt__:[23,1,1,""],affected_net:[23,2,1,""],id:[23,2,1,""],new_value:[23,2,1,""],time:[23,2,1,""]},"netlist_simulator.NetlistSimulator":{add_clock_frequency:[23,1,1,""],add_clock_period:[23,1,1,""],add_gates:[23,1,1,""],generate_vcd:[23,1,1,""],get_gates:[23,1,1,""],get_input_nets:[23,1,1,""],get_output_nets:[23,1,1,""],get_simulation_state:[23,1,1,""],get_simulation_timeout:[23,1,1,""],initialize:[23,1,1,""],initialize_sequential_gates:[23,1,1,""],load_initial_values:[23,1,1,""],load_initial_values_from_netlist:[23,1,1,""],reset:[23,1,1,""],set_input:[23,1,1,""],set_iteration_timeout:[23,1,1,""],set_simulation_state:[23,1,1,""],simulate:[23,1,1,""]},"netlist_simulator.NetlistSimulatorPlugin":{create_simulator:[23,1,1,""],get_name:[23,1,1,""],get_version:[23,1,1,""],name:[23,2,1,""],version:[23,2,1,""]},"netlist_simulator.Simulation":{__init__:[23,1,1,""],add_event:[23,1,1,""],get_events:[23,1,1,""],get_net_value:[23,1,1,""]},boolean_influence:{BooleanInfluencePlugin:[2,0,1,""]},dataflow:{DataflowPlugin:[5,0,1,""]},graph_algorithm:{GraphAlgorithmPlugin:[13,0,1,""]},hal_gui:{GuiApi:[15,0,1,""]},hal_py:{BasePluginInterface:[0,0,1,""],BooleanFunction:[1,0,1,""],CoreUtils:[3,4,0,"-"],DataContainer:[4,0,1,""],Endpoint:[6,0,1,""],FFComponent:[11,0,1,""],GUIPluginInterface:[16,0,1,""],Gate:[7,0,1,""],GateLibrary:[8,0,1,""],GateLibraryManager:[9,4,0,"-"],GateType:[10,0,1,""],GateTypeComponent:[11,0,1,""],GateTypeProperty:[12,0,1,""],Grouping:[14,0,1,""],HalPath:[26,0,1,""],InitComponent:[11,0,1,""],LUTComponent:[11,0,1,""],LatchComponent:[11,0,1,""],Module:[19,0,1,""],Net:[20,0,1,""],Netlist:[21,0,1,""],NetlistFactory:[22,4,0,"-"],NetlistUtils:[24,4,0,"-"],NetlistWriterManager:[25,4,0,"-"],PinDirection:[27,0,1,""],PinType:[28,0,1,""],RAMComponent:[11,0,1,""],RAMPortComponent:[11,0,1,""],StateComponent:[11,0,1,""],plugin_manager:[29,4,0,"-"]},netlist_simulator:{Event:[23,0,1,""],NetlistSimulator:[23,0,1,""],NetlistSimulatorPlugin:[23,0,1,""],Simulation:[23,0,1,""]}},objnames:{"0":["py","class","Python class"],"1":["py","method","Python method"],"2":["py","attribute","Python attribute"],"3":["py","staticmethod","Python static method"],"4":["py","module","Python module"],"5":["py","function","Python function"]},objtypes:{"0":"py:class","1":"py:method","2":"py:attribute","3":"py:staticmethod","4":"py:module","5":"py:function"},terms:{"1st":7,"2nd":7,"boolean":[7,8,10,11,17,24,30],"case":[8,9,23,24],"class":[0,1,2,4,5,6,7,8,10,11,12,13,14,15,16,19,20,21,23,26,27,28],"default":[3,10,11,21,24,28,29],"float":2,"function":[2,3,7,8,10,11,15,17,20,21,22,23,24,26,29],"int":[5,7,10,11,13,14,15,19,20,21,23,24],"new":[1,7,10,14,19,20,21,22,23,24],"return":[0,1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,19,20,21,22,23,24,25,29],"static":[1,3,11],"switch":5,"true":[1,4,6,7,8,9,10,11,14,15,16,19,20,21,23,24,25,29],"try":3,AND:1,For:[19,24],IDs:[13,14,21,24],NOT:1,ONE:1,The:[0,1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,19,20,21,22,23,24,25,29],Use:[3,20,23],Useful:23,__and__:1,__call__:1,__eq__:[1,23],__iand__:1,__init__:[1,6,8,10,23,26],__invert__:1,__ior__:1,__ixor__:1,__lt__:23,__ne__:1,__or__:1,__str__:[1,26],__xor__:1,abort:[20,23],about:[7,10,20,21],abov:24,accur:[6,10],act:14,activ:11,actual:23,add:[4,7,8,10,19,20,21,23],add_boolean_funct:[7,10],add_clock_frequ:23,add_clock_period:23,add_destin:20,add_ev:23,add_gat:23,add_includ:8,add_input_pin:10,add_output_pin:10,add_pin:10,add_sourc:20,added:[10,15,19,23,24],adding:24,addit:[11,23],addition:24,addr_group:11,address:[11,28],address_group:11,advanc:23,affect:23,affected_net:23,after:23,afterward:2,algorithm:[1,30],all:[1,4,7,8,9,10,11,14,15,19,20,21,23,24,25,29],allow:[14,24],alphabet:1,alreadi:[9,14],also:[1,19],alwai:1,analysi:30,analyz:24,analyze_input:24,ani:[10,11,14,19,24],anoth:[1,14,19],api:30,appear:2,appli:[1,8,10,11,14,19,21,23],applic:21,arg0:[1,10,23,26],arg:[1,15,20,21,22,23,24,26],ascend:11,assign:[7,10,14,19,20,21],assign_g:[14,19],assign_gate_by_id:14,assign_modul:14,assign_module_by_id:14,assign_net:14,assign_net_by_id:14,assign_pin_group:10,assign_pin_typ:10,assign_properti:10,associ:[4,6,7,10,14,19,20,21,23,29],async_reset_bf:11,async_reset_funct:11,async_set_bf:11,async_set_funct:11,asynchron:11,asyncsetresetbehavior:11,attempt:9,automat:[19,21,23],avail:[7,9,12,25],base:[3,7,17,19,20,24],baseplugininterfac:[0,29],basic:29,been:[9,10,21,23],befor:[1,10,15,23,24],beforehand:10,behav_neg_st:11,behav_st:11,behavior:11,being:13,belong:[10,11],better:24,between:23,binari:3,bit:[1,11],bit_siz:11,bool:[1,4,5,6,7,8,9,10,11,14,15,16,19,20,21,23,24,25,29],boolean_funct:[7,10],boolean_influ:2,booleanfunct:[1,7,10,11,23,24],booleaninfluenceplugin:2,both:[1,11,23],bracket:1,buffer:[12,24],build:2,bunction:1,cach:[19,21,24],call:[10,16,21,23,24,29],callabl:[7,8,10,11,14,19,20,21,23,24],camera:15,can:[1,7,13,14,19,20,21,23,24],candid:[10,11,24],care:9,carri:[12,23],categori:[4,7,11,19,20],caus:[23,24],cell:13,chain:24,chain_typ:24,chang:19,channel:[4,7,19,20],check:[1,6,7,8,10,11,14,19,20,21,24],child:11,classifi:24,claus:1,clear:[15,21],clear_cach:21,clear_current_select:15,clock:[11,23,28],clock_bf:11,clock_funct:11,clock_net:23,cluster:13,code:2,collect:[8,14],combin:[1,12,24],common:24,commun:13,compil:2,compon:[10,13,17],componenttyp:[10,11],compris:[1,6],condit:[8,10,11,14,19,21,23],config:3,configur:[3,23],connect:[6,7,13,14,19,20,24],consid:[23,24],constant:[1,7],construct:[1,8,23],contain:[1,3,7,8,10,11,14,17,19,20,21],contains_g:[14,19],contains_gate_by_id:14,contains_gate_typ:8,contains_gate_type_by_nam:8,contains_modul:[14,19],contains_module_by_id:14,contains_net:14,contains_net_by_id:14,content:18,continu:24,contrast:14,control:23,convert:1,coordin:[7,21],copi:24,copy_netlist:24,core:18,coreutil:3,correctli:24,correspond:[8,19],creat:[5,21,22,23],create_g:21,create_group:21,create_modul:21,create_net:21,create_netlist:22,create_simul:23,current:[3,15,21,23],custom:23,cut:13,cycl:23,dana:30,data:[2,7,11,17,19,20,23,28],data_group:11,data_in_bf:11,data_in_funct:11,data_typ:[4,7,19,20],datacontain:[4,7,19,20],dataflow:30,dataflowplugin:5,dataport:2,deep:24,defin:[7,8,11,23,24,27,28],delet:[4,7,19,20],delete_data:[4,7,19,20],delete_g:21,delete_group:21,delete_modul:21,delete_net:21,demnand:9,deprec:20,depth:[13,24],describ:[1,8,11],deselect:15,deselectallitem:15,deselectg:15,deselectmodul:15,deselectnet:15,design:[14,21],design_nam:21,desir:[24,29],destin:[6,19,20,23],detect:24,determin:[3,4,7,11,15,19,20],devic:21,device_nam:21,dict:[1,2,4,7,8,10,13,19,20,23,24],dictionari:[7,19],differ:24,direct:[7,10,17,19,24],directori:[3,9,29],directory_nam:29,dirti:19,disabl:[10,11,23],disjunct:1,dispatch:25,distanc:13,divice_nam:21,dnf:1,doe:[10,11,14,23],draw_graph:5,driven:[20,23],dsp:12,durat:23,dure:[1,14,23],dynam:24,each:[1,10,13,14,19,21,22],edg:23,effic:2,either:19,element:[20,23],empti:[1,7,10,11,20,22,24,29],enabl:[11,19,24,28],enable_bf:11,enable_funct:11,end:[23,24],end_gat:24,end_tim:23,endpoint:[7,17,20,24],entir:24,entiti:[4,14],entri:[4,7,19,20],environ:3,equal:[1,23],error:[1,20,21],especi:23,eval:2,evalu:[1,21,24],event:[4,7,19,20,23],ever:21,everi:[21,24],exampl:[1,7],exec:16,execut:[2,3,5],exist:[4,7,9,10,15,19,20,24],expect:24,explicit:[4,7,19,20],explicitli:21,explor:14,exponenti:1,expr:2,express:1,extens:24,extract:1,factori:17,fail:14,fals:[1,4,6,7,8,9,10,11,14,15,19,20,21,23,24,25,29],fan:[7,24],fan_in_net:7,fan_out_net:7,fast:13,faster:20,ffcompon:11,file:[3,8,9,21,22,23,25,29],file_path:[9,25,29],filenam:21,fill:24,filter:[7,8,10,11,14,19,20,21,23,24],find:[3,11,24],first:[1,7,19,20,24],fit:15,fix:24,flip:[2,11,12,13],flop:[2,11,12,13],follow:21,forc:[4,7,14,19,20],form:[1,24],found:[1,19,24],fpga:23,framework:29,free:19,freed:21,frequenc:23,from:[1,2,4,5,7,8,9,10,13,14,19,20,21,22,23,24,28],from_str:1,fulfil:24,func:7,function_nam:10,further:[9,13],gate:[2,3,5,6,13,14,15,17,19,20,21,22,23,24],gate_id:[14,15,21],gate_lib:9,gate_librari:[10,21,22],gate_library_fil:22,gate_typ:[7,8,21],gatelibrari:[8,9,10,21,22],gatelibrarymanag:9,gatetyp:[7,8,10,21,24],gatetypecompon:[10,11],gatetypeproperti:[10,12,24],gener:[2,5,16,23,24,28],generate_vcd:23,gerner:23,get:[0,1,2,3,4,5,6,7,8,9,10,11,13,14,15,19,20,21,23,24,29],get_address_group:11,get_async_reset_funct:11,get_async_set_funct:11,get_async_set_reset_behavior:11,get_base_directori:3,get_binary_directori:3,get_bit_s:11,get_boolean_funct:[7,10],get_boolean_influences_of_g:2,get_clock_funct:11,get_common_input:24,get_commun:13,get_communities_fast_greedi:13,get_communities_spinglass:13,get_complex_gate_chain:24,get_compon:[10,11],get_data:[4,7,19,20],get_data_group:11,get_data_in_funct:11,get_data_map:[4,7,19,20],get_default_log_directori:3,get_design_nam:21,get_destin:20,get_device_nam:21,get_dnf_claus:1,get_enable_funct:11,get_ev:23,get_fan_in_endpoint:7,get_fan_in_net:7,get_fan_out_endpoint:7,get_fan_out_net:7,get_free_gate_id:21,get_free_grouping_id:21,get_free_module_id:21,get_free_net_id:21,get_gat:[6,13,14,19,21,23],get_gate_by_id:[19,21],get_gate_chain:24,get_gate_id:14,get_gate_librari:[9,10,21],get_gate_library_by_nam:9,get_gate_library_directori:3,get_gate_typ:8,get_gate_type_by_nam:8,get_global_input_net:21,get_global_output_net:21,get_gnd_gat:21,get_gnd_gate_typ:8,get_graph_cut:13,get_group:[7,19,20,21],get_grouping_by_id:21,get_id:[7,10,14,19,20,21],get_includ:8,get_init_categori:11,get_init_identifi:11,get_input_filenam:21,get_input_net:[19,23],get_input_pin:[7,10],get_input_port_nam:19,get_input_port_net:19,get_internal_net:19,get_library_directori:3,get_loc:7,get_location_i:7,get_location_x:7,get_modul:[7,14,21],get_module_by_id:21,get_module_id:14,get_nam:[0,2,5,7,8,10,13,14,19,20,23],get_neg_state_identifi:11,get_net:[6,14,19,21],get_net_by_id:21,get_net_id:14,get_net_valu:23,get_netlist:[7,14,19,20],get_nets_at_pin:24,get_next_g:24,get_next_gate_id:21,get_next_grouping_id:21,get_next_input_port_id:19,get_next_module_id:21,get_next_net_id:21,get_next_output_port_id:19,get_next_sequential_g:24,get_next_state_funct:11,get_num_of_destin:20,get_num_of_sourc:20,get_output_net:[19,23],get_output_pin:[7,10],get_output_port_nam:19,get_output_port_net:19,get_parent_modul:19,get_path:[8,24],get_pin:[6,10],get_pin_direct:10,get_pin_group:10,get_pin_of_group_at_index:10,get_pin_typ:10,get_pins_of_direct:10,get_pins_of_group:10,get_pins_of_typ:10,get_plugin_directori:3,get_plugin_inst:29,get_plugin_nam:29,get_predecessor:7,get_properti:10,get_share_directori:3,get_shortest_path:24,get_simulation_st:23,get_simulation_timeout:23,get_sourc:20,get_state_identifi:11,get_strongly_connected_compon:13,get_subgraph_funct:24,get_submodul:19,get_successor:[7,24],get_top_modul:21,get_truth_t:1,get_typ:[7,11,19],get_unique_gate_id:21,get_unique_grouping_id:21,get_unique_module_id:21,get_unique_net_id:21,get_unique_predecessor:7,get_unique_successor:7,get_used_gate_id:21,get_used_grouping_id:21,get_used_module_id:21,get_used_net_id:21,get_user_config_directori:3,get_user_share_directori:3,get_vari:1,get_vcc_gat:21,get_vcc_gate_typ:8,get_vers:[0,2,5,13,23],getselectedg:15,getselectedgateid:15,getselecteditem:15,getselecteditemid:15,getselectedmodul:15,getselectedmoduleid:15,getselectednet:15,getselectednetid:15,given:[1,2,4,7,8,9,10,11,19,20,21,22,23,24,25],global:[7,19,20,21,23],global_input_net:21,global_output_net:21,gnd:[7,8,20,21],gnd_gate:21,gnd_gate_typ:8,graph:[5,15,30],graph_algorithm:13,graphalgorithmplugin:13,greedi:13,ground:[12,28],group:[5,7,10,11,17,19,20,21,24],grouping_id:21,gui:[4,7,17,19,20,30],guiapi:15,guiplugininterfac:16,hal:[3,6,7,9,10,11,18,19,20,21,22,23,24,25,29],hal_base_path:3,hal_fil:22,hal_gui:15,hal_path:[3,8,9,21,22,23,25,29],hal_pi:[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,19,20,21,22,23,24,25,26,27,28,29],halpath:[3,8,9,21,22,23,25,26,29],halpi:2,handl:[1,11,12,27,28],happen:23,has:[10,20,23],has_component_of_typ:10,has_data:[4,7,19,20],has_loc:7,has_properti:10,have:[9,10,19,21,23],hdl:3,hdl_file:22,help:[6,10],hertz:23,hierarch:[14,19],high:[1,5],higher:24,highest:21,hold:4,home:3,howev:24,ident:24,identifi:[5,11],ids:[15,21],igraph:13,iii:[10,11],imped:1,implement:24,improv:24,inc:8,includ:[1,7,8,10,19,20,21,23,24],index:[10,13,18],indic:10,indirect:19,infinit:23,influenc:[23,24,30],info:[4,7,19,20],inform:[7,10,20,21],init:11,init_ascend:11,init_categori:11,init_identifi:11,initcompon:11,initi:[6,10,11,23,24,28,29],initialize_sequential_g:23,initializi:11,inout:27,input:[1,2,6,7,9,10,11,19,20,21,23,24,27],input_filenam:21,input_net:19,input_pin:[7,10,24],input_port_nam:19,inspect:23,instal:3,instanc:[1,23],instead:20,intend:1,interconnect:24,interfac:[17,29],intern:[10,11,19,21,23,27,28],internal_net:19,interpret:[1,3],invalid:[21,27],io_pad:28,is_a_destin:20,is_a_sourc:20,is_class_of:11,is_constant_on:1,is_constant_zero:1,is_destin:6,is_destination_pin:6,is_dirti:19,is_dnf:1,is_empti:1,is_gate_in_netlist:21,is_global_input_net:[20,21],is_global_output_net:[20,21],is_gnd_gat:[7,21],is_gnd_net:20,is_grouping_in_netlist:21,is_init_ascend:11,is_input:24,is_module_in_netlist:21,is_net_in_netlist:21,is_sourc:6,is_source_pin:6,is_top_modul:19,is_unrout:20,is_vcc_gat:[7,21],is_vcc_net:20,is_writ:11,is_write_port:11,item:15,iter:23,its:[3,7,8,10,19,20,21,24,29],itself:24,keep:[9,25],kei:[4,7,19,20],known:[1,5],known_group:5,kwarg:[1,15,20,21,22,23,24,26],lambda:[7,8,10,11,14,19,20,21,23,24],last:24,latch:[11,12],latchcompon:11,layout:7,least:[1,19],leav:[7,20],len:20,length:24,level:[4,5,7,19,20],lib_nam:9,libnetlist_simul:23,librari:[3,10,17,21,22],like:7,limit:[13,24],list:[1,3,5,7,8,9,10,11,13,14,15,19,20,21,22,23,24,29],load:[9,22,23,29],load_al:9,load_all_plugin:29,load_initial_valu:23,load_initial_values_from_netlist:23,load_netlist:22,local:3,locat:[7,25],location_i:7,location_x:7,log:[3,4,7,19,20],log_with_info_level:[4,7,19,20],logic:[1,24],look:24,loop:[23,24],loos:19,lowest:24,lut:[11,12,24,28],lutcompon:11,mac:11,mai:[4,7,14,19,20,23,24],make:[10,24],manag:17,mani:24,map:[2,7,19,23],mark:[7,8,19,20,21],mark_global_input_net:[20,21],mark_global_output_net:[20,21],mark_gnd_gat:[7,21],mark_gnd_gate_typ:8,mark_vcc_gat:[7,21],mark_vcc_gate_typ:8,match:[1,8,10,11,14,19,21,22,23,24],maximum:23,mccluskei:1,member:[1,11,12,27,28],memori:13,might:1,mnetid:15,modifi:15,modul:[7,14,15,17,18,21,24],module_id:[14,15,21],more:24,most:1,move:19,multi:20,multipl:[7,10,11],must:[1,10,24],mux:12,name:[0,1,5,6,7,8,9,10,11,12,13,14,19,20,21,23,24,27,28,29],navigate_to_select:15,need:14,neg:7,neg_stat:28,neg_state_identifi:11,negat:[1,11,28],net:[2,6,7,14,15,17,19,21,23,24],net_id:[14,15,21],netlist:[4,5,7,8,13,14,16,17,19,20,30],netlist_simul:23,netlistfactori:22,netlistsimul:23,netlistsimulatorplugin:23,netlistutil:24,netlistwritermanag:25,new_par:19,new_valu:23,new_variable_nam:1,next:[11,19,21],next_input_port_id:19,next_output_port_id:19,next_state_bf:11,next_state_funct:11,none:[1,7,8,9,10,11,14,15,19,20,21,22,23,24,26,27,28],normal:1,nullptr:21,num_of_destin:20,num_of_sourc:20,number:[1,13,20,23,24],object:[3,8,16],off:5,old:[1,19,24],old_variable_nam:1,omit:24,one:[1,7,14,19,23,24],onli:[7,8,14,19,21,23,24],only_custom_funct:7,oper:[1,5,13],optim:1,optimize_const:1,option:[23,24],order:[1,11,24],ordered_vari:1,other:[19,23,24],otherwis:[1,3,4,6,7,8,9,10,11,14,19,20,21,22,23,24,25,29],out:[7,20,24],output:[1,6,7,9,10,19,20,21,23,24,25,27,28],output_net:19,output_path:5,output_pin:[7,10,24],output_port_nam:19,outsid:[19,23],overload:[1,15,20,21,22,23,24,26],overwrit:[4,7,9,14,19,20],pad:28,page:18,pair:[1,24],param:[1,7,15,20,21,22,23,24],paramet:[1,2,3,4,5,7,8,9,10,11,13,14,16,19,20,21,22,23,24,25,29],parent:[3,19,21],parent_modul:19,pars:[1,8],part:[1,8,23],pass:15,path:[3,5,8,9,17,21,22,23,24,25,29],perform:24,period:23,physic:7,picosecond:23,pin:[6,7,8,10,11,17,20,24],pin_direct:10,pin_group:10,pin_map:24,pin_nam:10,pin_typ:10,pindirect:[10,27],pintyp:[10,28],place:1,plain:1,plugin:[3,5,13,17,18,23],plugin_manag:29,plugin_nam:29,point:[13,23],port:[7,11,19],port_nam:19,posit:[7,15],possibl:[1,24],potenti:[7,20],power:[12,28],pre:22,preced:1,predeccessor:24,predecessor:[7,24],present:24,previou:[14,15,19],previous:[5,21],primarili:19,print:20,priorit:5,process:[19,23],properti:[10,17,24],provid:[3,10,11,23,24],python3:3,quin:1,ram:[11,12],ram_port:11,ramcompon:11,ramportcompon:11,reach:24,read:11,recommend:24,recurs:[19,24],recus:19,reflect:24,regard:[7,19],regist:[5,21],rel:3,relat:14,releas:29,relev:23,reload:9,remov:[1,14,19,20,21,23,24],remove_buff:24,remove_destin:20,remove_g:[14,19],remove_gate_by_id:14,remove_modul:14,remove_module_by_id:14,remove_net:14,remove_net_by_id:14,remove_sourc:20,remove_unknown_vari:1,remove_unused_lut_endpoint:24,renam:[1,24],rename_luts_according_to_funct:24,repeat:24,replac:[1,24],replace_g:24,repres:[1,7,13,21],represent:1,requir:[8,21,24],reserv:21,reset:[7,11,23,28],resourc:29,respect:[6,7,23,24,25],ressourc:29,result:[1,14,19,21,24],revers:24,rise:23,rtype:[1,20,21,22,24],run:[13,16],runtim:1,rytp:11,said:2,same:[11,24],save:9,scc:13,schedul:23,scroll:15,search:[3,18,19,24,29],search_both_direct:24,see:[6,10],select:[15,23,28],selectg:15,selectmodul:15,selectnet:15,self:[0,1,2,4,5,6,7,8,10,11,12,13,14,15,16,19,20,21,23,26,27,28],sequenc:24,sequenti:[12,23,24],set:[5,7,10,11,12,13,14,19,20,21,23,24,28,29],set_address_group:11,set_async_reset_funct:11,set_async_set_funct:11,set_async_set_reset_behavior:11,set_bit_s:11,set_cache_dirti:19,set_clock_funct:11,set_data:[4,7,19,20],set_data_group:11,set_data_in_funct:11,set_design_nam:21,set_device_nam:21,set_enable_funct:11,set_free_gate_id:21,set_free_grouping_id:21,set_free_module_id:21,set_free_net_id:21,set_id:21,set_init_ascend:11,set_init_categori:11,set_init_identifi:11,set_input:23,set_input_filenam:21,set_input_port_nam:19,set_iteration_timeout:23,set_loc:7,set_location_i:7,set_location_x:7,set_nam:[7,14,19,20],set_neg_state_identifi:11,set_next_gate_id:21,set_next_grouping_id:21,set_next_input_port_id:19,set_next_module_id:21,set_next_net_id:21,set_next_output_port_id:19,set_next_state_funct:11,set_output_port_nam:19,set_parent_modul:19,set_simulation_st:23,set_state_identifi:11,set_typ:19,set_used_gate_id:21,set_used_grouping_id:21,set_used_module_id:21,set_used_net_id:21,set_write_port:11,shall:24,share:3,shorter:24,shortest:24,should:[5,24],show:15,signal:23,signatur:[6,10],signific:1,simpl:24,simul:30,sinc:[1,20,21,23],singl:[1,10,11,14,23,29],size:[5,11],sort:[19,23],sourc:[3,6,19,20],source_fil:3,spare:21,specif:[7,13,23,24],specifi:[4,7,8,10,11,13,14,19,20,21,22,23,24,29],speciif:10,spin:13,spinglass:13,ssc:13,stai:5,standard:9,start:[5,13,23,24],start_at_zero:23,start_gat:24,start_tim:23,startup:23,state:[11,23,28],state_identifi:11,statecompon:11,std:10,step:24,stop:24,stop_properti:24,store:[4,7,14,19,20],str:[0,1,2,4,5,6,7,8,9,10,11,12,13,14,19,20,21,22,23,24,26,27,28,29],string:[1,10,11,28],strongli:13,subgraph:24,subgraph_g:24,submodul:19,subset:24,substitut:1,succ:21,succesor:24,success:[4,7,8,9,10,14,16,19,20,21,22,23,24,25,29],successor:[7,24],suppli:[1,7,20],support:[1,11],sure:10,tabl:1,take:9,target:[21,24],target_typ:24,task:25,temporarili:14,term:1,termin:13,terminal_gate_typ:13,test:23,than:[20,24],theresult:24,theshold:24,thi:[1,7,8,10,14,19,20,21,23,24],threshold:24,through:24,thu:1,time:[11,19,23],timefram:23,timeout:23,to_dnf:1,top:[19,21],top_modul:[19,21],trace:[4,7,19,20],track:[9,25],translat:2,travers:24,treat:23,tri:5,truth:1,tupl:[1,4,7,10,11,15,19,20],turn:5,two:[1,23],type:[0,1,2,3,4,5,6,7,8,9,13,14,15,16,17,19,20,21,22,23,24,25,29],typic:21,undefin:1,underli:21,unequ:1,uniqu:[7,10,14,19,20,21,23,29],unique_predecessor:7,unique_successor:7,unix:3,unknown:[7,23],unload:29,unload_all_plugin:29,unmark:[7,20,21],unmark_global_input_net:[20,21],unmark_global_output_net:[20,21],unmark_gnd_g:[7,21],unmark_vcc_g:[7,21],unrout:20,unstructur:14,until:24,untouch:5,usag:24,use:[3,24],used:[1,2,7,9,19,21,24,25],user:[3,8,10,23,24],using:[1,7,22,24],usual:7,util:[1,17],valid:7,valu:[1,4,7,11,19,20,21,23,24],variabl:[1,3,24],variable_nam:1,variant:24,vcc:[7,8,20,21],vcc_gate:21,vcc_gate_typ:8,vcd:23,vector:[1,3,19,24],version:[0,5,13,20,23,24],vhdl:8,via:7,view:15,wai:14,walk:1,warn:[1,20],well:[10,19,21],were:7,when:[1,11,23,24],whenev:1,where:[3,5,24],whether:[1,4,6,7,8,10,11,14,19,20,21,23,24],which:[1,2,7,11,13,15,19,20,24],which_pin:7,wire:23,within:[8,9,14,19,21,23,24,25],word:24,write:[11,23,25],write_port:11,writer:17,written:5,xor:1,yet:23,zero:1,zoom:15},titles:["Base Plugin Interface","Boolean Function","Boolean Influence","Core Utils","Data Container","Dataflow Analysis (DANA)","Endpoint","Gate","Gate Library","Gate Library Manager","Gate Type","Gate Type Component","Gate Type Property","Graph Algorithms","Grouping","GUI API","GUI Plugin Interface","HAL Core Documentation","hal_py Documentation","Module","Net","Netlist","Netlist Factory","Netlist Simulator","Netlist Utils","Netlist Writer Manager","HAL Path","Pin Direction","Pin Type","Plugin Manager","HAL Plugins Documentation"],titleterms:{"boolean":[1,2],"function":1,algorithm:13,analysi:5,api:15,base:0,compon:11,contain:4,core:[3,17],dana:5,data:4,dataflow:5,direct:27,document:[17,18,30],endpoint:6,factori:22,gate:[7,8,9,10,11,12],graph:13,group:14,gui:[15,16],hal:[17,26,30],hal_pi:18,indic:18,influenc:2,interfac:[0,16],librari:[8,9],manag:[9,25,29],modul:19,net:20,netlist:[21,22,23,24,25],path:26,pin:[27,28],plugin:[0,16,29,30],properti:12,simul:23,tabl:18,type:[10,11,12,28],util:[3,24],writer:25}})